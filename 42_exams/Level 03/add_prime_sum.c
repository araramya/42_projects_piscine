/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <stdlib.h>

int ft_is_space(char c);
int ft_atoi(const char *str);
void ft_putnum(int num);
int ft_is_prime(int num);

int main(int argc, char **argv)
{
	int num;
	int sum;
	int i;
	

	if(argc != 2)
	{
		write(1,"0\n", 2);
		return (0);
	}

	if(argc == 2)
	{
		sum = 0;
		num = ft_atoi(argv[1]);
		if (num <= 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		while(i <= num)
		{ 
			if (ft_is_prime(i))
				sum = sum + i;
			i++;
		}
		ft_putnum(sum);
		write(1 ,"\n", 1);
	}

}

int ft_is_space(char c)
{
	if(c == '\n' || c == '\f' || c == '\t' || c == '\v' || c == '\r' || c == ' ')
		return (1);
	return (0);
}
int ft_atoi( const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign *= -1;
		str++;
	}
	while(*str)
	{
		if(*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
			return(result * sign);
		str++;
	}
	return(result * sign);
}
int ft_is_prime(int num)
{
	int i;
	i = 2;
	if (num <= 1)
		return (0);
	while(i <= num/i)
	{
		if(num % i == 0)
			return (0);
		i++;
	}
	return (1);
}
void ft_putnum( int num )
{
	char c;
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	if (num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else 
	{
		ft_putnum(num / 10);
		ft_putnum(num % 10);
	}
}