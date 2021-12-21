/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:58:03 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 19:55:01 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *piles)
{
	int	tmp;

	if (piles->len_a <= 1)
		return ;
	tmp = piles->tab_a[0];
	piles->tab_a[0] = piles->tab_a[1];
	piles->tab_a[1] = tmp;
	write_string("sa\n");
}

void	swap_b(t_piles *piles)
{
	int	tmp;

	if (piles->len_b <= 1)
		return ;
	tmp = piles->tab_b[0];
	piles->tab_b[0] = piles->tab_b[1];
	piles->tab_b[1] = tmp;
	write_string("sb\n");
}

void	swap_swap(t_piles *piles)
{
	swap_a(piles);
	swap_b(piles);
}
