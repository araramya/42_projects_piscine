/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaramyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:47:59 by aaramyan          #+#    #+#             */
/*   Updated: 2020/09/20 19:48:15 by aaramyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_manager(int x, char start, char mid, char end)
{
	ft_putchar(start);
	while ((x - 1) > 1)
	{
		ft_putchar(mid);
		x--;
	}
	if (x > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_print_manager(x, 'A', 'B', 'C');
		y--;
		while (y > 1)
		{
			ft_print_manager(x, 'B', ' ', 'B');
			y--;
		}
		if (y > 0)
			ft_print_manager(x, 'A', 'B', 'C');
	}
}
