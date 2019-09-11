#include <stdio.h>
#include <stdlib.h>
#include "../libs/priority_queue.h"
#include "../libs/huffman_tree.h"

int isEmpty(PRIORITY_QUEUE *pq)
{
    return (pq->size == 0);
}

PRIORITY_QUEUE *createEmptyQueue()
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    pq->head = NULL;
    pq->size = 0;
    return pq;
}

void enqueue(PRIORITY_QUEUE *pq, NODE_TREE *node_tree)
{
    NODE_TREE *aux = node_tree;
    if (pq->size == 0)
    {
        pq->size++;
        aux->next = pq->head;
        pq->head = aux;
    }
    else
    {
        pq->size++;
        NODE_TREE *current = pq->head;
        NODE_TREE *previous = NULL;
        while ((current != NULL) && (current->frequency < aux->frequency))
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
        aux->next = current;
    }
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

PRIORITY_QUEUE *enqueue_f_array(int frequency_array[])
{
    PRIORITY_QUEUE *pq = (PRIORITY_QUEUE *)malloc(sizeof(PRIORITY_QUEUE));
    pq->head = NULL;
    NODE_TREE *node_tree;
    int i;

    for (i = 0; i < ASCII_SIZE; i++)
    {
        if (frequency_array[i])
        {
            node_tree = build_node_tree(i, frequency_array[i], NULL, NULL);
            enqueue(pq, node_tree);
        }
    }
    return pq;
}

NODE_TREE *dequeue(PRIORITY_QUEUE *pq)
{
    NODE_TREE *head = pq->head;
    pq->head = pq->head->next;
    pq->size--;
    return head;
}

void printing_pq(PRIORITY_QUEUE *pq)
{
    NODE_TREE *node = pq->head;

    while (node != NULL)
    {
        printf("%c (%d)\n", node->character, node->frequency);
        node = node->next;
    }
    printf("\n");
}