/*Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/
#include <unistd.h>
void putnbr(int argc)
{
	char c;
	if (argc < 0)
	{
		write(1, "-", 1);
		argc = -argc;
	}
	else if(argc < 10)
	{
		c = argc + '0';
		write(1 , &c, 1);
	}
	else 
	{
		putnbr(argc/10);
		putnbr(argc%10);
	}
}
int main(int argc, char **argv)
{
	putnbr(argc);
	write(1,"\n",1);
	return(0);
}