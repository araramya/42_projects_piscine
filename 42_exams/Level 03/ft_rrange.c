
/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/
#include <stdlib.h> // for malloc
#include <stdio.h> // for checking

int *ft_rrange(int start, int end)
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
		array[i] = end;
		end--;
		i++;
	}
	while(start >= end)
	{
		array[i] = end;
		end++;
		i++;
	}
	return(array);
}

//checking
int main()
{
    int temp;
	int start = 0;
	int end = -3;
	int *array = ft_rrange(start, end);
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
