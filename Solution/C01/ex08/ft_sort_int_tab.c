/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaramyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 20:04:32 by aaramyan          #+#    #+#             */
/*   Updated: 2020/09/23 20:10:54 by aaramyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int x;
	int y;
	int swap;

	x = 0;
	while (x < size - 1)
	{
		y = x + 1;
		while (y < size)
		{
			if (tab[x] > tab[y])
			{
				swap = tab[x];
				tab[x] = tab[y];
				tab[y] = swap;
			}
			y++;
		}
		x++;
	}
}
