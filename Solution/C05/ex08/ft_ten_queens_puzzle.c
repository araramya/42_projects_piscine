/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaramyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:23:26 by aaramyan          #+#    #+#             */
/*   Updated: 2020/10/03 14:23:32 by aaramyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_print_sol(int *board)
{
	int			index;
	char		c;

	index = -1;
	while (++index < 10)
	{
		c = board[index] + 48;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int				ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

int				ft_check_place(int *board, int index)
{
	int			okay;
	int			o_index;

	okay = 1;
	o_index = -1;
	while (++o_index < index && okay)
	{
		if (board[index] == board[o_index])
			okay = 0;
		if (ft_abs(o_index - index) == ft_abs(board[o_index] - board[index]))
			okay = 0;
	}
	return (okay);
}

void			ft_place_queens(int index, int *count)
{
	static	int	board[10] = {0};
	int			pos;

	pos = -1;
	while (++pos < 10)
	{
		board[index] = pos;
		if (ft_check_place(board, index))
		{
			if (index < 9)
				ft_place_queens(index + 1, count);
			else
			{
				++(*count);
				ft_print_sol(board);
			}
		}
	}
}

int				ft_ten_queens_puzzle(void)
{
	int			count;

	count = 0;
	ft_place_queens(0, &count);
	return (count);
}
