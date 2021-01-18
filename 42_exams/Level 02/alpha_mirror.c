//a b c d e f g h i j  k  l  m    n  o  p  q  r  s  t  u  v  w  x  y  z
//1 2 3 4 5 6 7 8 9 10 11 12 13  14 15 16 17 18 19 20 21 22 23 24 25 26
/*Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	
	i = 0;
	if(argc == 2)
	{
		while(argv[1][i])
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				argv[1][i] = 'z' - ( argv[1][i] - 'a') ;
			}
			else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				argv[1][i] = 'Z' -( argv[1][i] - 'A' );
			}
			
				write(1, &argv[1][i], 1);
			i++;

		}
	}
	write(1, "\n", 1);
	return (0);
}

