/* 
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/
//start of ft_list.h file
#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct s_list
{
	struct s_list *next;
	void		  *data; 
	
}			    t_list;

#endif
//end of ft_list.h file

//start of ft_list_size.c
#include "ft_list"
int ft_list_size(t_list *begin_list)
{
	int size;
	size = 0;
	while(begin_list)
	{
		begin_list = begin_list -> next;
		size++;
	}
	return(size);
}

//checking

