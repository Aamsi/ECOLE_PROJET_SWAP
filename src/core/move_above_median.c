/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_above_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:22:00 by iouali            #+#    #+#             */
/*   Updated: 2021/12/22 18:20:19 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bot_index(t_piles *piles)
{
	int i;

	i = piles->len_a - 1;
	while (i >= 0)
	{
		if (piles->tab_a[i] > piles->median)
			return (i);
		i--;
	}
	return (-1);
}

static int get_top_index(t_piles *piles)
{
	int i;

	i = 0;
	while (i < piles->len_a)
	{
		if (piles->tab_a[i] > piles->median)
			return (i);
		i++;
	}
	return (-1);
}

static int	above_median_exists(t_piles *piles)
{
	int	index_top;
	int	index_bot;
	int	middle_len;

	middle_len = piles->len_a / 2;
	while (1)
	{
		index_top = get_top_index(piles);
		index_bot = get_bot_index(piles);
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

void	move_above_median_to_b(t_piles *piles)
{
	int i;
	int reverse;;

    i = 0;
	reverse = above_median_exists(piles);
    while (reverse >= 0)
    {
        if (piles->tab_a[0] > piles->median)
            push_b(piles);
        else if (reverse > 0)
            reverse_rotate_a(piles);
		else
			rotate_a(piles);
		reverse = above_median_exists(piles);
    }
}
