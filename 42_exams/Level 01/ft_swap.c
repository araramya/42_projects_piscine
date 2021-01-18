/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/
#include <stdio.h>
#include <unistd.h>

void ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
// checking
int main()
{
	int a = 7;
	int b = 8;
	int *p1 = &a;
	int *p2 = &b;
	printf("%i\n",a );
	printf("%i\n",b );
	ft_swap(p1,p2);
	printf("%i\n",a );
	printf("%i\n",b );
}