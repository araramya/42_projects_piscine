/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/


#include <unistd.h>
int ft_isspace (char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
			c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i;

	if(argc == 2)
	{
		while(ft_isspace(argv[1][i]))
			i += 1;
		while(argv[1][i])
		{
			if (!ft_isspace(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				
			}
			
			if(ft_isspace(argv[1][i]) && !(ft_isspace(argv[1][i+1])))
			{
				if(argv[1][i+1] != '\0')
					write(1," ",1);
				
			}
			i++;
			
		}
	}
	write(1, "\n", 1);
	return(0);
}