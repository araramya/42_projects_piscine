/*Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>*/
#include <unistd.h>

int ft_is_space (char c)
{
	if(c == '\n'|| c== '\t'|| c == '\v'|| c == '\r'|| c == '\f'|| c == ' ')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int p;
	int i;
	p = 1;
	if(argc > 1)
 {
	while(p < argc)
	{
		i = 0;
		while(argv[p][i])
		{
			if(!ft_is_space(argv[p][i]))
			{
				if(argv[p][i] >= 'A' && argv[p][i] <= 'Z')
					argv[p][i]+=32;
				if(i == 0 || ft_is_space(argv[p][i - 1]))
					if(argv[p][i] >= 'a' && argv[p][i] <= 'z')
						argv[p][i] -= 32;
			}
			write(1, &argv[p][i], 1);
	         i++;
		}
		write(1, "\n", 1);
		p++;
	}
 }
 else 
 	write(1, "\n", 1);
 return(0);
}