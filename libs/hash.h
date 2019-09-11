#ifndef _HASH_
#define _HASH_

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

/**
 * @typedef HASH_TABLE
 * 
 * @discussion Hash Table Properties
 * 
 * @field matrix Where will be stored the bit string in the character line
 * 
*/
typedef struct HASH_TABLE
{
    void *matriz[ASCII_SIZE][ASCII_SIZE];
} HASH_TABLE;

/** @discussion Initialize hash matrix with empty spaces
 * 
 * @result An initialized hash table
 */
extern HASH_TABLE *creating_hash_table();

/** @discussion You get an initialized hash table, the huffman tree leaf character, the size of the bit sequence 
 * calculated at the time you traversed the tree, and the bit sequence itself. 
 * 
 * @param hash_table An initially empty hash table
 * @param character The Tree Leaf Character
 * @param index The index indicating the maximum position of the bit_sequency array
 * @param bit_sequency The bit sequence stored at the time you walked through the huffman tree
 * 
 * @result The hash table filled in at the character position entered with the bit string passed in the parameter
 */
extern void put_in_hash(HASH_TABLE *hash_table, U_CHAR character, int index, U_CHAR bit_sequency[]);

extern int is_bit_i_set(U_CHAR c, int i);

extern U_CHAR set_bit(U_CHAR c, int i);

/** @discussion You get an initially empty hash table, the pre-assembled huffman tree, an initially zeroed index, 
 * and an initially empty array that will store the sequence of bits (0's and 1's) as you travel through 
 * the huffman tree
 * 
 * @param hash_table An initially empty hash table
 * @param tree The pre-assembled huffman tree
 * @param i The index for the bitstream array
 * @param bit_sequency A char array that will store the bit sequence
 * 
 */
extern void walking_in_the_tree(HASH_TABLE *hash_table, NODE_TREE *tree, int i, U_CHAR bit_sequency[]);

#endif