/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe  not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
	

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int start;

	i = 0;
	start = 0;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{ 
		if((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i+1] != ' ' && argv[1][i] != '\t' && argv[1][i+1] != '\0')
			start = i+1;
		i++;
	}
	while(argv[1][start] != ' ' && argv[1][i] != '\t' && argv[1][start] != '\0')
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}
///OR
/*
#include <unistd.h>

void	last_word(char *str)
{
	int	start;
	int i;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
			start = i + 1;
		i++;
	}
	while (str[start] >= 33 && str[start] <= 127)
	{
		write(1, &str[start], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
///or */
