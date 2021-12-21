/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_after_sort_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:48:16 by iouali            #+#    #+#             */
/*   Updated: 2021/12/21 20:20:21 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigger(t_piles *piles)
{
	int i;
	int	bigger;

	i = 0;
	bigger = piles->tab_b[i];
	while (i < piles->len_b)
	{
		if (piles->tab_b[i] > bigger)
			bigger = piles->tab_b[i];
		i++;
	}
	return (bigger);
}

static int	get_bot_index(t_piles *piles, int bigger)
{
	int i;

	i = piles->len_b - 1;
	while (i >= 0)
	{
		if (piles->tab_b[i] == bigger)
			return (i);
		i--;
	}
	return (-1);
}

static int get_top_index(t_piles *piles, int bigger)
{
	int i;

	i = 0;
	while (i < piles->len_b)
	{
		if (piles->tab_b[i] == bigger)
			return (i);
		i++;
	}
	return (-1);
}

int	reverse(t_piles *piles, int bigger)
{
	int	index_top;
	int	index_bot;
	int	middle_len;

	middle_len = piles->len_b / 2;
	while (piles->tab_b >= 0)
	{
		index_top = get_top_index(piles, bigger);
		index_bot = get_bot_index(piles, bigger);
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

void	move_to_a(t_piles *piles)
{
	int bigger;
	int i;
	int is_reverse;

	bigger = get_bigger(piles);
	is_reverse = reverse(piles, bigger);
	i = 0;
	while (is_reverse >= 0)
	{
		if (piles->tab_b[0] == bigger)
			push_a(piles);
		else if (is_reverse > 0)
			reverse_rotate_b(piles);
		else
			rotate_b(piles);
		bigger = get_bigger(piles);
		is_reverse = reverse(piles, bigger);
	}
}
