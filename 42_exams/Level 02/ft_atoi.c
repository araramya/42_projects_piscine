/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/
#include <stdio.h>

int ft_isspace (char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
			c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;

	while(ft_isspace(*str))
		str++;
	while(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign *= -1;
		str++;
	}
	while(*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
		}
		else
			return (result * sign);
		str++;
	}
	return (result * sign);
}
// checking
int main()
{
    char str[] = "  --+-+--537ab78";
    printf("%d", ft_atoi(str));
}
