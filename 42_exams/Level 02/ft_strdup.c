/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
	char *cpy;
	int i;
	int size;

	i = 0;
	size = 0;
	while(src[size])
		size++;
	if(!(cpy = (char*) malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return(cpy);
}
// checking
int main()
{
    char src[] = "Arsenchik";
    printf("%s", ft_strdup(src));
}