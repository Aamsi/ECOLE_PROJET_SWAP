/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quantiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:26:21 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 17:45:56 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_quantiles(t_piles *piles)
{
	int *sorted_array;
	int	len;
	int	divided;

	len = piles->len_a - 1;
	divided = len / 11;
	sorted_array = sort_array(piles);
	if (!sorted_array)
		return ;
	piles->q1 = sorted_array[divided];
	piles->q2 = sorted_array[2 * divided];
	piles->q3 = sorted_array[3 * divided];
	piles->q4 = sorted_array[4 * divided];
	piles->q5 = sorted_array[5 * divided];
	piles->q6 = sorted_array[6 * divided];
	piles->q7 = sorted_array[7 * divided];
	piles->q8 = sorted_array[8 * divided];
	piles->q9 = sorted_array[9 * divided];
	piles->q10 = sorted_array[10 * divided];
	piles->q11 = sorted_array[len];
	free(sorted_array);
}
