#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libs/frequency.h"

#define ASCII_SIZE 256

typedef unsigned char U_CHAR;

void create_frequency_array(FILE *file, int freq[])
{
    U_CHAR character;
    while (fscanf(file, "%c", &character) != EOF)
    {
        freq[character] += 1;
    }
}

void printing_frequency_array(int *array)
{
    int i;
    for (i = 0; i < ASCII_SIZE; i++)
    {
        if (array[i])
        {
            /** Displays character and frequency */
            printf("%c %d\n", i, array[i]);
        }
    }
}