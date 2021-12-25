/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:12:38 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 17:09:18 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_already_sorted(t_piles *piles)
{
	int	i;

	i = 0;
	while (i < piles->len_a - 1)
	{
		if (piles->tab_a[i] > piles->tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	route_algo(t_piles *piles)
{
	if (piles->len_a == 1 || check_already_sorted(piles))
		return ;
	if (piles->len_a <= 5)
	{
		sort_five_or_less(piles);
	}
	else if (piles->len_a > 5 && piles->len_a <= 100)
	{
		find_median(piles);
		move_above_median_to_b(piles);
		move_to_a(piles);
		move_under_median_to_b(piles);
		move_to_a(piles);
	}
	else if (piles->len_a > 100)
	{
		find_median(piles);
		find_quantiles(piles);
		solve_under_500(piles);
	}
}
