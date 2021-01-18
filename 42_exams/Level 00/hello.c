/*Expected files   : hello.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays "Hello World!" followed by a \n.

Example:

$>./hello
Hello World!
$>./hello | cat -e
Hello World!$
$>
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
	write(1,"Hello World!\n", 13);
}