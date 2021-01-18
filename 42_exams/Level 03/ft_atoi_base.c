/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <stdlib.h> // for checking
#include <stdio.h> // for checking

int ft_is_space(char c)
{
	if (c <= 32)
		return (1);
	return(0);
}
int ft_is_valid(char c, int str_base)
{
	char str1[17] = "0123456789abcdef";
	char str2[17] = "0123456789ABCDEF";

	while(str_base--)
		if(str1[str_base] == c || str2[str_base] == c)
			return (1);
		return(0);
}
int value_of(char c)
{
	if(c >= '0' && c<= '9')
		return (c - '0');
	else if(c >= 'a' && c <= 'f')
		return(c - 'a' + 10);
	else if(c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while(ft_is_space(*str))
		str++;
	while(*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while(ft_is_valid(*str, str_base))
	{
		result = result * str_base + value_of(*str);
		str++;
	}
	return(result*sign);
}


//checking
int main()
{
  printf("%d\n", ft_atoi_base("1234f", 16));
  return 0;
}