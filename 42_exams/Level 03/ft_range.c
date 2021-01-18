
/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdlib.h> // for malloc
#include <stdio.h> // for checking

int *ft_range(int start, int end)
{
	int *array;
	int size;
	int i;
	
	
    i = 0;
    if(start > end)
        size = start - end + 1;
    else
        size = end - start + 1;
	
	array = (int*) malloc (size * sizeof(int));
	while(start <= end)
	{
		array[i] = start;
		start++;
		i++;
	}
	while(start >= end)
	{
		array[i] = start;
		start--;
		i++;
	}
	return(array);
}

//checking
int main()
{
    int temp;
	int start = 1;
	int end = 5;
	int *array = ft_range(start, end);
	if(start > end)
    {
        temp =  start;
        start = end;
        end = temp;
    }
	while(start <= end)
	{
		printf("%d", *array);
		start++;
		array++;
	}
}