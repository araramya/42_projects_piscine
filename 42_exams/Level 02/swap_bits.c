/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 */
#include <unistd.h>
#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octet << 4));
}
//checking
int main()
{
    unsigned char octet = '5';
    write(1,&octet,1);
    write(1,"\n",1);
    printf("%c",swap_bits(octet));
    
}