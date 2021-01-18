  /*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character of each word (if it's a letter) in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
premieR petiT tesT$
$> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
deuxiemE tesT uN peU moinS  facilE$
   attentioN c'esT paS duR quanD memE$
alleR uN dernieR 0123456789pouR lA routE    E $
$>
*/
#include <unistd.h>
int ft_is_space(char c)
{
	if(c== '\n' || c == '\v' || c == '\t' || c == '\r' || c == '\f' || c == ' ' )
		return(1);
	return(0);
}
int main(int argc, char **argv)
{
	int i;
	int param;
	if (argc > 1)
	{
		
		param = 1;
		while(param < argc)
		{
			i = 0;
			while(argv[param][i])
			{
				if(!(ft_is_space(argv[param][i])))
				{
					if(argv[param][i]>= 'A' && argv[param][i] <= 'Z')
						argv[param][i]+= 32;
					if(ft_is_space(argv[param][i+1]) || argv[param][i+1] == '\0')
					{
						if(argv[param][i] >= 'a' && argv[param][i] <= 'z')
							argv[param][i] -= 32;
					}
				}
				write(1, &argv[param][i], 1);
				i++;
			}
			write(1, "\n", 1);
			param++;
		}

	}
	else
	 write(1,"\n",1);
		return(0);
}
