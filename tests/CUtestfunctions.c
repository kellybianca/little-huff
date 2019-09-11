#include <stdio.h>
#include <string.h>
#define ASCII_SIZE 256
typedef unsigned char U_CHAR;

typedef struct NODE_TREE
{
    U_CHAR character;
    int frequency;
    struct NODE_TREE *left;
    struct NODE_TREE *right;
    struct NODE_TREE *next;
} NODE_TREE;

typedef struct PRIORITY_QUEUE
{
    NODE_TREE *head;
    int size;
} PRIORITY_QUEUE;

typedef struct HASH_TABLE
{
    void *matriz[ASCII_SIZE][ASCII_SIZE];
} HASH_TABLE;

HASH_TABLE *create_hash()
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

NODE_TREE *build_node_tree(U_CHAR character, int frequency, NODE_TREE *left, NODE_TREE *right)
{
    NODE_TREE *node_tree = (NODE_TREE *)malloc(sizeof(NODE_TREE));
    node_tree->character = character;
    node_tree->frequency = frequency;
    node_tree->next = NULL;
    node_tree->left = left;
    node_tree->right = right;

    return node_tree;
}

void enqueue(PRIORITY_QUEUE *pq, NODE_TREE *node_tree)
{
    NODE_TREE *aux = node_tree;
    if (pq->size == 0)
    {
        pq->size++;
        // aux->next = pq->head;
        pq->head = aux;
    }
    else
    {
        pq->size++;
        NODE_TREE *current = pq->head;
        NODE_TREE *previous = NULL;
        while ((current == NULL) && (current->frequency > aux->frequency))
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            aux->next = pq->head;
            pq->head = aux;
            return;
        }
        previous->next = aux;
        // aux->next = current;
    }
}

NODE_TREE *dequeue(PRIORITY_QUEUE *pq)
{
    NODE_TREE *head = pq->head;
    pq->head = pq->head->next;
    pq->size--;
    return head;
}

NODE_TREE *build_node(PRIORITY_QUEUE *pq)
{
    NODE_TREE *node_huff = create_node();
    PRIORITY_QUEUE *aux = pq;
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