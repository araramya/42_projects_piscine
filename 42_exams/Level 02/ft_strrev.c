/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/
#include <stdio.h>
char *ft_strrev(char *str)
{
	int len;
	int i;
	char helper;

	len = 0;
	i = -1;

	while(str[len])
		len++;
	while(--i < ++len)
	{
		helper = str[i];
		str[i] = str[len];
		str[len] = helper;
	}
	return (str);
	return (str);

}

//checking
int main()
{
	char str[]= "Arsen "
	printf("%s", ft_strrev(str) );
}