#ifndef _HUFFMAN_TREE_
#define _HUFFMAN_TREE_

/**
 * @typedef U_CHAR 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_CHAR;
/**
 * @typedef lli
 * 
 * @discussion Used to shorten type name
 */
typedef long long int lli;

/**
 * @typedef NODE_TREE
 * 
 * @discussion All properties of node are stored in this structure
 * 
 * @field character Characters stored in the file
 * @field frequency Frequency of each character above
 * @field left Pointer to the left child
 * @field rigth Pointer to the right child
 * @field next Pointer to next node of priority queue
 * 
*/
typedef struct NODE_TREE
{
    U_CHAR character;
    int frequency;
    struct NODE_TREE *left;
    struct NODE_TREE *right;
    struct NODE_TREE *next;
} NODE_TREE;

/** @discussion Create an empty huffman node
 * 
 * @result An empty knot of huffman tree
 */
extern NODE_TREE *create_node();

/**
 * @discussion Receives two nodes and creates a parent node in the tree by adding the '*' symbol
 * 
 * @param node1 The first lowest frequency node in the queue
 * @param node2 The second lowest frequency node in the queue
 * 
 * @result A node of huffman tree
 */
extern NODE_TREE *huffman_create_node(NODE_TREE *node1, NODE_TREE *node2);

/**
 * @discussion Saves the tree in preorder, character by character, within the file
 * 
 * @param bt The mounted huffman tree
 * 
 * @result The huffman tree written in preorder in the file
 */
extern void put_tree(NODE_TREE *bt, FILE *output);

/**
 * @discussion Receives the priority queue and creating tree nodes from the first least frequent nodes 
 * until there is only one node in the queue
 * 
 * @param pq The priority queue mounted from their characters and frequencies in the file
 * 
 * @result A node of huffman tree
 */
extern NODE_TREE *build_node(PRIORITY_QUEUE *pq);

/**
 * @discussion Take a node from huffman tree and check if it is empty
 * 
 * @param node_tree A node of huffman tree
 * 
 * @result An integer indicating whether it's (1) or not (0) empty
 */
extern int isEmptyTree(NODE_TREE *node_tree);

/**
 * @discussion Get the huffman tree and check if it's a leaf
 * 
 * @param tree Huffman's tree
 * 
 * @result An integer indicating whether it's (1) or not (0) empty
 */
extern int isLeaf(NODE_TREE *tree);

/**
 * @discussion Get the huffman tree and print it in preorder
 * 
 * @param node_tree Huffman's tree
 * 
 * @result The tree printed in preorder
 */
extern void print_pre_order(NODE_TREE *node_tree);

/**
 * @discussion You get the huffman tree, a pointer to its size (initially zeroed) and an array 
 * (initially empty) to save the tree in preorder as you calculate its size.
 * 
 * @param tree Huffman's tree
 * @param size A pointer to tree size
 * @param tree_preorder An array to save the tree in preorder
 * 
 * @result The size of the tree and it saves in preorder to an array
 */
extern void size_tree_and_preorder(NODE_TREE *tree, lli *size);

#endif
