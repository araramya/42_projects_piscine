/*Assignment name  : ft_print_numbers
Expected files   : ft_print_numbers.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays all digits in ascending order.

Your function must be declared as follows:

void	ft_print_numbers(void);
*/

#include<stdio.h>
#include<unistd.h>
void	ft_print_numbers(void);
{
	write(1, "0123456789", 10);
}
