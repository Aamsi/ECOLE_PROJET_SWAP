/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_quantile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:41:37 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 17:14:13 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bot_index(t_piles *piles, int q_min, int q_max)
{
	int i;

	i = piles->len_a - 1;
	while (i >= 0)
	{
		if (piles->tab_a[i] >= q_min && piles->tab_a[i] < q_max)
			return (i);
		i--;
	}
	return (-1);
}

static int	get_top_index(t_piles *piles, int q_min, int q_max)
{
	int i;

	i = 0;
	while (i < piles->len_a)
	{
		if (piles->tab_a[i] >= q_min && piles->tab_a[i] < q_max)
			return (i);
		i++;
	}
	return (-1);
}

int	in_quantile_exists(t_piles *piles, int q_min, int q_max)
{
	int	index_top;
	int	index_bot;
	int	middle_len;

	middle_len = piles->len_a / 2;
	while (1)
	{
		index_top = get_top_index(piles, q_min, q_max);
		index_bot = get_bot_index(piles, q_min, q_max);
		if (index_bot == -1 && index_top == -1)
			break ;
		if (index_bot < middle_len)
			return (0);
		if (index_top >= middle_len)
			return (1);
		if (get_abs(index_top - middle_len) < get_abs(index_bot - middle_len))
			return (1);
		else
			return (0);
	}
	return (-1);
}

void	move_in_quantile_to_b(t_piles *piles, int q_min, int q_max)
{
	int	i;
	int	reverse;

	i = 0;
	reverse = in_quantile_exists(piles, q_min, q_max);
	while (reverse >= 0)
	{
		if (piles->tab_a[0] >= q_min && piles->tab_a[0] < q_max)
			push_b(piles);
		else if (reverse > 0)
			reverse_rotate_a(piles);
		else
			rotate_a(piles);
		reverse = in_quantile_exists(piles, q_min, q_max);
	}
}

void	solve_under_500(t_piles *piles)
{
	move_in_quantile_to_b(piles, piles->q4, piles->q5 + 1);
	// print_debug(piles);
	move_to_a(piles);
	move_in_quantile_to_b(piles, piles->q3, piles->q4 + 1);
	// print_debug(piles);
	move_to_a(piles);
	// print_debug(piles);
	move_in_quantile_to_b(piles, piles->q2, piles->q3);
	// print_debug(piles);
	move_to_a(piles);
	// print_debug(piles);
	move_in_quantile_to_b(piles, piles->q1, piles->q2);
	// print_debug(piles);
	move_to_a(piles);
	// print_debug(piles);
	move_in_quantile_to_b(piles, get_smallest(piles), piles->q1);
	// print_debug(piles);
	move_to_a(piles);
	// print_debug(piles);
	move_above_median_to_b(piles);
	move_to_a(piles);
	move_under_median_to_b(piles);
	move_to_a(piles);
	// print_debug(piles);
}
