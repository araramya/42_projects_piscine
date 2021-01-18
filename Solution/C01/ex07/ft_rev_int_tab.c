/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaramyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:10:53 by aaramyan          #+#    #+#             */
/*   Updated: 2020/09/22 17:11:52 by aaramyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		index;
	int		temp;
	int		swap;

	index = 0;
	temp = size - 1;
	while (index < (size / 2))
	{
		swap = tab[index];
		tab[index] = tab[temp];
		tab[temp] = swap;
		index++;
		temp--;
	}
}
