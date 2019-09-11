#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/compress.h"
#include "../libs/huffman_tree.h"

void get_trash_size(NODE_TREE *tree, int height, U_CHAR *trash_size)
{
    if (!isEmptyTree(tree))
    {
        if (isLeaf(tree))
        {
            *trash_size += tree->frequency * height;
            height += 1;
        }
        get_trash_size(tree->left, height + 1, trash_size);
        get_trash_size(tree->right, height + 1, trash_size);
    }
}

int is_bit_i_set(U_CHAR c, int i)
{
    U_CHAR mask = 1 << i;

    return mask & c;
}

U_CHAR set_bit(U_CHAR c, int i)
{
    U_CHAR mask = 1 << i;

    return mask | c;
}

void print_byte(int bytes[], int pos)
{
    int i;
    for (i = 7; i >= 0; i--)
    {
        if (is_bit_i_set(bytes[pos], i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile, lli sizetree)
{
    U_CHAR character, byteFile = 0;
    int i, j = 0, size = 0, bit_amount = 0, byte_size = 7;

    rewind(compressedFile);
    fseek(compressedFile, 2 + sizetree, SEEK_SET);
    while (fscanf(file, "%c", &character) != EOF)
    {
        j = 0;
        while (hash_table->matriz[character][j] != (U_CHAR *)'\0')
        {
            if (hash_table->matriz[character][j] != (U_CHAR *)'0')
            {
                byteFile = set_bit(byteFile, byte_size);
            }
            bit_amount++;
            byte_size--;
            j++;

            if (bit_amount == 8)
            {
                fprintf(compressedFile, "%c", byteFile);
                byteFile = 0;
                byte_size = 7;
                bit_amount = 0;
            }
        }
    }
    if (bit_amount != 0)
    {
        fprintf(compressedFile, "%c", byteFile);
    }
    printf("Successfully compressed file...\n\n");

    fclose(compressedFile);
}