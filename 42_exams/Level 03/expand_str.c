/*Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

int ft_is_space( char c)
{
	if(c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	if(argc == 2)
	{
		i = 0;
		while(ft_is_space(argv[1][i]))
			i++;
		while(argv[1][i])
		{
			if(!ft_is_space(argv[1][i]))
				write(1, &argv[1][i], 1);
			if(ft_is_space(argv[1][i]) && !(ft_is_space(argv[1][i+1])))
			{
				if(argv[1][i+1]!= '\0')
					write(1, "   ", 3);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}