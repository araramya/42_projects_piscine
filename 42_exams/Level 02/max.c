/*
Assignment name  : max_value
Expected files   : max_value.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max_value(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
int		max_(int *tab, unsigned int len)
{
	int i;
	int max_value;
	i = 1;
	if(!tab)
		return (0);
	max_value = tab[0];
	while(len--)
	{
		if (tab[i] > max_value)
			max_value = tab[i];
		i++;
	}
	return (max_value);

}

// checking
int main()
{
	int tab[] = {56, 78, 97, 45, 32, 150};
	printf("%d", max(tab, 6) );
}