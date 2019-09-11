#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/huffman_tree.h"
#include "../libs/decompress.h"
#include "../libs/compress.h"

NODE_TREE *create_tree_preorder(NODE_TREE *node_tree, FILE *compressed)
{
    U_CHAR character;
    fscanf(compressed, "%c", &character);

    if (character == '*')
    {
        node_tree = create_node();
        node_tree->character = '*';
        node_tree->left = create_tree_preorder(node_tree->left, compressed);
        node_tree->right = create_tree_preorder(node_tree->right, compressed);
    }
    else
    {
        if (character == '\\')
        {
            fscanf(compressed, "%c", &character);
        }
        node_tree = create_node();
        node_tree->character = character;
    }
    return node_tree;
}

void start_decompress(FILE *compressed, U_CHAR *type)
{
    U_CHAR character;

    int trash = 0, sizeTree = 0, aux2 = 0, a[1], bytes[2] = {0}, i;

    fscanf(compressed, "%c", &character);

    printf("\nGetting the trash size...\n\n");
    trash = character >> 5;

    printf("Getting the tree size...\n\n");
    sizeTree = (character << 3) & (0xFF);
    sizeTree = sizeTree << 5;

    fscanf(compressed, "%c", &character);
    sizeTree |= character;

    NODE_TREE *node = create_node();
    printf("Riding the tree...\n\n");
    node = create_tree_preorder(node, compressed);
    printf("Starting decompression...\n\n");

    U_CHAR out_file[ASCII_SIZE];
    strcpy(out_file, "descompactado.");
    strcat(out_file, type);

    U_CHAR aux = 0;

    FILE *decompress_file = fopen(out_file, "wb");
    int size = 0;

    while (fscanf(compressed, "%c", &character) != EOF)
    {
        size++;
    }

    rewind(compressed);
    fseeko(compressed, 2 + sizeTree, SEEK_SET);

    NODE_TREE *tree = node;
    while (size > 1)
    {
        fscanf(compressed, "%c", &character);
        if (size != 1)
        {
            for (i = 7; i >= 0; i--)
            {
                if (is_bit_i_set(character, i))
                {
                    tree = tree->right;
                }
                else
                {
                    tree = tree->left;
                }
                if (isLeaf(tree))
                {
                    fprintf(decompress_file, "%c", tree->character);
                    tree = node;
                }
            }
        }
        size--;
    }

    fscanf(compressed, "%c", &character);
    for (i = 7; i >= trash; i--)
    {
        if (is_bit_i_set(character, i))
        {
            tree = tree->right;
        }
        else
        {
            tree = tree->left;
        }
        if (isLeaf(tree))
        {
            fprintf(decompress_file, "%c", tree->character);
            tree = node;
        }
    }
    printf("Successfully decompressed file...\n\n");
    fclose(compressed);
    fclose(decompress_file);
}