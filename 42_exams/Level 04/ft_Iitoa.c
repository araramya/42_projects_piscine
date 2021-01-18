/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdio.h> // checking
#include <stdlib.h>

int length(long nbr)
{
	int len;
	
	len = 0;
	if(nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while(nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int i;
	long num;
	char *str;

	num = nbr;
	i = length(num);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return(NULL);
	str[i--] = '\0';
	if(num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	if(num == 0)
	{
		str[0] = '0';
		return(str);
	}
	while(num > 0)
	{
		str[i] = (num % 10) + '0';
		i--;
		num /= 10;
	}
	return(str);
}

//cheking
int main()
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
