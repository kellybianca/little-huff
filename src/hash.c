#include <stdio.h>
#include <stdlib.h>
#include "../libs/hash.h"
#include "../libs/huffman_tree.h"

/**
 * @define ASCII_SIZE
 * 
 * @discussion Maximum array size
*/
#define ASCII_SIZE 256

HASH_TABLE *creating_hash_table()
{
    HASH_TABLE *new_hash_table = (HASH_TABLE *)malloc(sizeof(HASH_TABLE));

    int i, j;
    for (i = 0; i < ASCII_SIZE; i++)
    {
        for (j = 0; j < ASCII_SIZE; j++)
        {
            new_hash_table->matriz[i][j] = (U_CHAR *)' ';
        }
    }
    return new_hash_table;
}

void put_in_hash(HASH_TABLE *hash_table, U_CHAR character, int index, U_CHAR bit_sequency[])
{
    int i;
    for (i = 0; i < index; i++)
    {
        hash_table->matriz[character][i] = (U_CHAR)bit_sequency[i];
    }
    hash_table->matriz[character][i] = '\0';
}

void walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree, int i, U_CHAR bit_sequency[])
{
    if (isEmptyTree(tree))
    {
        return;
    }
    if (isLeaf(tree))
    {
        put_in_hash(hash_table, tree->character, i, bit_sequency);
        return;
    }
    bit_sequency[i] = '0';
    walking_in_the_tree(hash_table, tree->left, i + 1, bit_sequency);

    bit_sequency[i] = '1';
    walking_in_the_tree(hash_table, tree->right, i + 1, bit_sequency);
}

void print_hash(HASH_TABLE *hash)
{
    int i, j;

    for (i = 0; i < ASCII_SIZE; i++)
    {
        if (hash->matriz[i][0] != (U_CHAR)' ')
        {
            printf("%c: ", i);
            for (j = 0; j < ASCII_SIZE; j++)
            {
                printf("%c", (U_CHAR *)hash->matriz[i][j]);
            }
            printf("\n");
        }
    }
}