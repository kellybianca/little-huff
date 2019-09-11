#ifndef _COMPRESS_
#define _COMPRESS_

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

/** @discussion Get the Huffman tree ready, its size initially reset, a pointer to the size of the trash
 *  and calculate the size of the tree and the trash
 * 
 * @param tree Huffman's Tree
 * @param height Will store tree size
 * @param trash_size Will store trash size in tree
 * 
 * @result The tree trash
 */
extern void get_trash_size(NODE_TREE *tree, int height, U_CHAR *trash_size);

extern int is_bit_i_set(U_CHAR c, int i);

extern U_CHAR set_bit(U_CHAR c, int i);

/** @discussion Get a byte array for the garbage and tree size, the index, and print the bits (each byte)
 * 
 * @param bytes An array of bytes
 * @param pos The array index indicating the byte
 * 
 * @result The byte print (bit a bit)
 */
extern void print_byte(int bytes[], int pos);

/** @discussion Get the file from the menu, the hash_table assembled with the bits of each character, 
 * the file to be compressed and the size of the tree to use to know from which position of the file to start 
 * writing the bits.
 * 
 * @param file The file that was reported to be compressed
 * @param hash_table The hash table with the bits at their respective character positions
 * @param compressedFile The compressed file
 * @param sizeTree The size of the tree created from file characters
 * 
 * @result The bytes written to the file
 */
extern void write_to_file(FILE *file, HASH_TABLE *hash_table, FILE *compressedFile, lli sizetree);

#endif