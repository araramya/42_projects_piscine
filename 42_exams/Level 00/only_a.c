  /*
Assignment name  : only_a
Expected files   : only_a.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a 'a' character on the standard output.*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	write(1, "a", 1);
	return (0);
}