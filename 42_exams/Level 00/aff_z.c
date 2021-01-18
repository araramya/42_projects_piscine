/*Assignment name  : aff_z
Expected files   : aff_z.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the first 'z'
character it encounters in it, followed by a newline. If there are no
'z' characters in the string, the program writes 'z' followed
by a newline. If the number of parameters is not 1, the program displays
'z' followed by a newline.

Example:

$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "dubO a POIL" | cat -e
$
$> ./aff_z "zaz sent le poney" | cat -e
z$
$> ./aff_z | cat -e
z$
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
	write(1, "z\n", 2);
}

//or way for itiodt
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int i;
	i = 0;
	if (argc != 2)
		write(1, "z\n", 2);
	else
	{
		while(argv[1][i])
		{
			if (argv[1][i] == 'z')
			{
				write(1, "z\n", 2);
				goto hi;
			}
			i++;
		}
		write(1,"z\n",2);
	}
	hi:
	return (0);
}