/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:57:11 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 20:07:19 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_piles *piles)
{
	int	tmp;
	int	i;
	int	*new_tab;

	if (piles->len_a <= 1)
		return ;
	new_tab = malloc(sizeof(int) * piles->len_a);
	if (!new_tab)
		return ;
	tmp = piles->tab_a[piles->len_a - 1];
	new_tab[0] = tmp;
	i = 1;
	while(i < piles->len_a)
	{
		new_tab[i] = piles->tab_a[i - 1];
		i++;
	}
	free(piles->tab_a);
	piles->tab_a = new_tab;
	write_string("rra\n");
}

void	reverse_rotate_b(t_piles *piles)
{
	int	tmp;
	int	i;
	int	*new_tab;

	if (piles->len_b <= 1)
		return ;
	new_tab = malloc(sizeof(int) * piles->len_b);
	if (!new_tab)
		return ;
	tmp = piles->tab_b[piles->len_b - 1];
	new_tab[0] = tmp;
	i = 1;
	while(i < piles->len_b)
	{
		new_tab[i] = piles->tab_b[i - 1];
		i++;
	}
	free(piles->tab_b);
	piles->tab_b = new_tab;
	write_string("rrb\n");
}

void	reverse_rotate_rotate(t_piles *piles)
{
	reverse_rotate_a(piles);
	reverse_rotate_b(piles);
}
