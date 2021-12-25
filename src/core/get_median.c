/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:02:39 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 18:02:13 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(t_piles *piles)
{
	int	i;
	int	*new_tab;

	new_tab = malloc(sizeof(int) * piles->len_a);
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < piles->len_a)
	{
		new_tab[i] = piles->tab_a[i];
		i++;
	}
	return (new_tab);
}

int	*sort_array(t_piles *piles)
{
	int	i;
	int	j;
	int	tmp;
	int	*new_tab;

	new_tab = copy_array(piles);
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < piles->len_a)
	{
		j = 0;
		while (j < piles->len_a - 1)
		{
			if (new_tab[j] > new_tab[j + 1])
			{
				tmp = new_tab[j];
				new_tab[j] = new_tab[j + 1];
				new_tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (new_tab);
}

void	find_median(t_piles *piles)
{
	int	*sorted_array;
	int	len;

	len = piles->len_a;
	sorted_array = sort_array(piles);
	if (!sorted_array)
		return ;
	piles->median = sorted_array[len / 2];
	free(sorted_array);
}
