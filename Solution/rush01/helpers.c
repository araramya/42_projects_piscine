/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:36:56 by vtorosya          #+#    #+#             */
/*   Updated: 2020/09/27 20:38:06 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include.h"

t_views	parse_arg(char *arg)
{
	int		i;
	int		j;
	t_views views;

	views = init_square(4);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (arg[i] == ' ')
		{
			arg++;
			continue;
		}
		views[j][i % 4] = arg[i] - '0';
		if (i % 4 == 3)
			j++;
		i++;
	}
	return (views);
}

int		**init_square(int size)
{
	int i;
	int j;
	int **square;

	square = malloc(sizeof(int*) * size);
	i = 0;
	while (i < size)
	{
		square[i] = malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
			square[i][j++] = 0;
		i++;
	}
	return (square);
}

int		**dup_square(int **square)
{
	int **clone;
	int	i;
	int	j;

	clone = init_square(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			clone[i][j] = square[i][j];
			j++;
		}
		i++;
	}
	return (clone);
}

void	destroy_square(int **square)
{
	int i;

	i = 0;
	while (i < 4)
		free(square[i++]);
	free(square);
}

void	print_square(t_board board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(board[i][j]);
			j++;
			if (j != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
