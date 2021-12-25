/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:22:34 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 18:02:48 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_three(t_piles *piles)
{
	int	top;
	int	middle;
	int	bot;

	bot = piles->tab_a[2];
	middle = piles->tab_a[1];
	top = piles->tab_a[0];
	if (middle < top && middle < bot && bot > top)
		swap_a(piles);
	else if (middle < top && middle < bot && top > bot)
		rotate_a(piles);
	else if (middle > top && middle > bot && top > bot)
		reverse_rotate_a(piles);
	else if (middle > bot && middle < top)
	{
		swap_a(piles);
		reverse_rotate_a(piles);
	}
	else if (middle > top && middle > bot && bot > top)
	{
		swap_a(piles);
		rotate_a(piles);
	}
}

int	get_smallest(t_piles *piles)
{
	int	smallest;
	int	i;

	smallest = piles->tab_a[0];
	i = 1;
	while (i < piles->len_a)
	{
		if (piles->tab_a[i] < smallest)
			smallest = piles->tab_a[i];
		i++;
	}
	return (smallest);
}

void	sort_under_four(t_piles *piles)
{
	int	smallest;

	smallest = get_smallest(piles);
	while (piles->tab_a[0] != smallest)
		rotate_a(piles);
	push_b(piles);
	sort_under_three(piles);
	push_a(piles);
}

void	sort_under_five(t_piles *piles)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if (piles->tab_a[0] < piles->median)
		{
			push_b(piles);
			i++;
		}
		else
			rotate_a(piles);
	}
	sort_under_three(piles);
	if (piles->tab_b[0] < piles->tab_b[1])
		swap_b(piles);
	push_a(piles);
	push_a(piles);
}

void	sort_five_or_less(t_piles *piles)
{
	if (piles->len_a == 2 && piles->tab_a[0] > piles->tab_a[1])
		swap_a(piles);
	else if (piles->len_a == 3)
		sort_under_three(piles);
	else if (piles->len_a == 4)
		sort_under_four(piles);
	else if (piles->len_a == 5)
		sort_under_five(piles);
}
