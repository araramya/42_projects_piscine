/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtorosya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:28:00 by vtorosya          #+#    #+#             */
/*   Updated: 2020/09/27 20:29:41 by vtorosya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	solve(t_board board, t_views views, int *solved)
{
	int		row;
	int		col;
	int		i;
	t_board	board_clone;

	if (!find_next_unassigned(board, &row, &col))
		return (TRUE);
	i = 0;
	while (++i <= 4)
	{
		if (!is_alone(board, row, col, i))
			continue ;
		board_clone = dup_square(board);
		board_clone[row][col] = i;
		if (solve(board_clone, views, solved)
			&& check_viewpoints(board_clone, views))
		{
			*solved = TRUE;
			print_square(board_clone);
			destroy_square(board_clone);
			return (TRUE);
		}
		destroy_square(board_clone);
	}
	return (FALSE);
}

int	find_next_unassigned(t_board board, int *row, int *col)
{
	*row = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (board[*row][*col] == UNASSIGNED)
				return (TRUE);
			(*col)++;
		}
		(*row)++;
	}
	return (FALSE);
}

int	is_alone(t_board board, int row, int col, int building_floor)
{
	int i;

	i = 0;
	while (i < 4)
		if (board[row][i++] == building_floor)
			return (FALSE);
	i = 0;
	while (i < 4)
		if (board[i++][col] == building_floor)
			return (FALSE);
	return (TRUE);
}

int	check_viewpoints(t_board board, t_views views)
{
	t_view_point	view;
	int				j;

	view = col_up;
	while (view <= row_right)
	{
		j = 0;
		while (j < 4)
		{
			if (!check_line(board, view, j, views[view][j]))
				return (FALSE);
			j++;
		}
		view++;
	}
	return (TRUE);
}

int	check_line(t_board board, t_view_point view, int view_line,
				int building_viewed)
{
	int	i;
	int	tmp_building_floor;

	i = 0;
	while (i < 4)
	{
		tmp_building_floor = get_with_view(board, view, view_line, i);
		if (tmp_building_floor == UNASSIGNED)
			return (FALSE);
		building_viewed--;
		while (i + 1 < 4 && tmp_building_floor > get_with_view(
					board, view, view_line, i + 1))
			i++;
		i++;
	}
	return (building_viewed == 0);
}
