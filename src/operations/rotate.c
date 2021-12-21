/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:43:22 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 20:02:22 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_piles *piles)
{
	int	tmp;
	int	i;
	int	*new_tab;

	if (piles->len_a <= 1)
		return ;
	new_tab = malloc(sizeof(int) * piles->len_a);
	if (!new_tab)
		return ;
	tmp = piles->tab_a[0];
	i = 0;
	while (i < piles->len_a - 1)
	{
		new_tab[i] = piles->tab_a[i + 1];
		i++;
	}
	new_tab[i] = tmp;
	free(piles->tab_a);
	piles->tab_a = new_tab;
	write_string("ra\n");
}

void	rotate_b(t_piles *piles)
{
	int	tmp;
	int	i;
	int	*new_tab;

	if (piles->len_b <= 1)
		return ;
	new_tab = malloc(sizeof(int) * piles->len_b);
	if (!new_tab)
		return ;
	tmp = piles->tab_b[0];
	i = 0;
	while (i < piles->len_b - 1)
	{
		new_tab[i] = piles->tab_b[i + 1];
		i++;
	}
	new_tab[i] = tmp;
	free(piles->tab_b);
	piles->tab_b = new_tab;
	write_string("rb\n");
}

void	rotate_rotate(t_piles *piles)
{
	rotate_a(piles);
	rotate_b(piles);
}
