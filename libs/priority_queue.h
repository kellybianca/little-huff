#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

/**
 * @typedef NODE_TREE
 * 
 * @discussion Defines a structure for NODE_TREE, huffman tree node, declared in huffman_tree.h
 * 
*/
typedef struct NODE_TREE NODE_TREE;

/**
 * @typedef PRIORITY_QUEUE
 * 
 * @discussion Properties of PRIORITY_QUEUE (head) are stored in this structure
 * 
 * @field head Pointer to the first node in the queue
 * @field size Integer indicating queue size
*/
typedef struct PRIORITY_QUEUE
{
    NODE_TREE *head;
    int size;
} PRIORITY_QUEUE;

/** @discussion Checks if queue is empty
 * 
 * @param pq A priority queue
 * 
 * @result true (1) or false (0)
 */
extern int isEmpty(PRIORITY_QUEUE *pq);

/**
 * @discussion You receive a cell from the priority queue and the data to add to it
 *             Add the parameter data in the queue
 * 
 * @param pq A priority queue
 * @param node_tree Huffman node created from queue
 * 
 * @result Queued huffman node
 */
extern void enqueue(PRIORITY_QUEUE *pq, NODE_TREE *node_tree);

/**
 * @discussion Get its character and frequency in the previously created frequency array, and a pointer 
 * to its left and right child and create a huffman node
 * 
 * @param character File character
 * @param frequency Frequency of each character saved in frequency array
 * @param left Pointer to the left child of the node
 * @param right Pointer to the right node child
 * 
 * @result A huffman node created from his frequency in the frequency array
 */
extern NODE_TREE *build_node_tree(U_CHAR character, int frequency, NODE_TREE *left, NODE_TREE *right);

/** @discussion Get the previously calculated frequency array and create huffman nodes from each frequency
 * 
 * @param frequency_array A frequency array
 * 
 * @result A priority queue with frequency
 */
extern PRIORITY_QUEUE *enqueue_f_array(int frequency_array[]);

/**
 * @discussion Get a priority queue, remove node from head and shrink queue size
 * 
 * @param pq A priority queue
 * 
 * @result The pointer to node dequeued
 */
extern NODE_TREE *dequeue(PRIORITY_QUEUE *pq);

/** @discussion Prints all priority queue data 
 * 
 * @param pq The printout of all queue values
 */
extern void printing_pq(PRIORITY_QUEUE *pq);

#endif
