/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int main(int argc, char **argv)
{
	unsigned char *s1;
	unsigned char *s2;
	int i;
	int temp[256];

	i = 0;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (i < 256)
		{
			temp[i] = 0;
			i++;
		}
		i = 0;
		while(s1[i])
		{
			if (temp[s1[i]] == 0)
			{
				write (1, &s1[i], 1);
				temp[s1[i]] = 1;
			}
			i++;
		}
		i =  0;
		while(s2[i])
		{
			if (temp[s2[i]] == 0)
			{
				write  (1, &s2[i], 1);
				temp[s2[i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}