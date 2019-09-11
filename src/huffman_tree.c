#include <stdio.h>
#include <stdlib.h>
#include "../libs/huffman_tree.h"
#include "../libs/priority_queue.h"

/**
 * @define ANSI_COLOR_RED
 * 
 * @discussion Inserts cyan color into terminal
*/
#define ANSI_COLOR_CYAN "\033[1;36m"

/**
 * @define ANSI_COLOR_RESET
 * 
 * @discussion Returns to the default print color
*/
#define ANSI_COLOR_RESET "\033[0;0m"

NODE_TREE *create_node()
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->frequency = 0;
    node_tree->left = NULL;
    node_tree->right = NULL;
    node_tree->next = NULL;
    return node_tree;
}

NODE_TREE *huffman_create_node(NODE_TREE *node1, NODE_TREE *node2)
{
    NODE_TREE *node_huff = (NODE_TREE *)malloc(sizeof(NODE_TREE));

    node_huff->left = node1;
    node_huff->right = node2;
    node_huff->character = '*';
    if (node2 == NULL)
    {
        node_huff->frequency = node1->frequency;
    }
    else
    {
        node_huff->frequency = node1->frequency + node2->frequency;
    }
    node_huff->next = NULL;

    return node_huff;
}

void put_tree(NODE_TREE *bt, FILE *output)
{
    if (bt != NULL)
    {
        if ((bt->character == '*' || bt->character == '\\') && bt->left == NULL && bt->right == NULL)
        {
            fputc('\\', output);
        }
        fputc(bt->character, output);
        put_tree(bt->left, output);
        put_tree(bt->right, output);
    }
}

NODE_TREE *build_node(PRIORITY_QUEUE *pq)
{
    NODE_TREE *node_huff = create_node();
    if (pq->size == 1)
    {
        return huffman_create_node(pq->head, NULL);
    }
    while (pq->size > 1)
    {
        NODE_TREE *node1 = dequeue(pq);
        NODE_TREE *node2 = dequeue(pq);
        node_huff = huffman_create_node(node1, node2);

        enqueue(pq, node_huff);
    }
    return pq->head;
}

int isEmptyTree(NODE_TREE *node_tree)
{
    return (node_tree == NULL);
}

int isLeaf(NODE_TREE *tree)
{
    return ((tree->left == NULL) && (tree->right == NULL));
}

void print_pre_order(NODE_TREE *node_tree)
{
    if (node_tree != NULL)
    {
        printf(ANSI_COLOR_CYAN "%c\n", node_tree->character);
        print_pre_order(node_tree->left);
        print_pre_order(node_tree->right);
    }
    printf(ANSI_COLOR_RESET);
}

void size_tree_and_preorder(NODE_TREE *tree, lli *size)
{
    // printf("entrou na sizetree\n");
    if (tree == NULL)
    {
        return;
    }
    if (isLeaf(tree))
    {
        if (tree->character == '*' || tree->character == '\\')
        {
            *size += 1;
        }
    }
    *size += 1;
    size_tree_and_preorder(tree->left, size);
    size_tree_and_preorder(tree->right, size);
}