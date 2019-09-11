#ifndef _DECOMPRESS_
#define _DECOMPRESS_

#include "./huffman_tree.h"

/**
 * @define ASCII_SIZE
 * 
 * @discussion Maximum array size
*/
#define ASCII_SIZE 256

/**
 * @typedef U_CHAR 
 * 
 * @discussion Uses unsigned char to preserve the pattern and the most significant bit to lose its function as signal bit
 */
typedef unsigned char U_CHAR;

/** @discussion You get an initially empty huffman tree node and compressed file so you can mount the tree 
 * in preorder from the third byte of the file
 * 
 * @param node_tree The initially empty tree
 * @param compressed The compressed file
 * 
 * @result The pre-assembled compressed archive tree
 */
extern NODE_TREE *create_tree_preorder(NODE_TREE *node_tree, FILE *compressed);

/** @discussion Get the compressed file and the type of extension it had before compressing, calculate trash size
 *  in first 3 bits of first byte, size of tree in last 5 bits of first byte and second byte, create tree in 
 * pre order and start decompression from each file character
 * 
 * @param compressed The compressed file
 * @param type The file extension type before being compressed
 * 
 * @result The uncompressed file
 */
extern void start_decompress(FILE *compressed, U_CHAR *type);

#endif