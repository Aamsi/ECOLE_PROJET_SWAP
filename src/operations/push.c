/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:14:37 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 19:48:37 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*insert_first_pos(int *former_tab, int *new_tab, int to_copy, int len)
{
	int		i;

	i = 0;
	new_tab[i] = to_copy;
	while (i < len)
	{
		new_tab[i + 1] = former_tab[i];
		i++;
	}
	free(former_tab);
	return (new_tab);
}

int	*delete_first_pos(int *former_tab, int *new_tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		new_tab[i] = former_tab[i + 1];
		i++;
	}
	free(former_tab);
	return (new_tab);
}

void	push_a(t_piles *piles)
{
	int tmp;
	int	*new_tab_a;
	int	*new_tab_b;

	if (piles->len_b == 0)
		return ;
	piles->len_a++;
	piles->len_b--;
	new_tab_a = malloc(sizeof(int) * piles->len_a);
	if (!new_tab_a)
		return ;
	new_tab_b = malloc(sizeof(int) * piles->len_b);
	if (!new_tab_b)
		return ;
	tmp = piles->tab_b[0];
	piles->tab_a = insert_first_pos(piles->tab_a, new_tab_a, tmp, piles->len_a - 1);
	piles->tab_b = delete_first_pos(piles->tab_b, new_tab_b, piles->len_b);
	write_string("pa\n");
}

void	push_b(t_piles *piles)
{
	int tmp;
	int	*new_tab_a;
	int	*new_tab_b;

	if (piles->len_a == 0)
		return ;
	piles->len_a--;
	piles->len_b++;
	new_tab_a = malloc(sizeof(int) * piles->len_a);
	if (!new_tab_a)
		return ;
	new_tab_b = malloc(sizeof(int) * piles->len_b);
	if (!new_tab_b)
		return ;
	tmp = piles->tab_a[0];
	piles->tab_b = insert_first_pos(piles->tab_b, new_tab_b, tmp, piles->len_b - 1);
	piles->tab_a = delete_first_pos(piles->tab_a, new_tab_a, piles->len_a);
	write_string("pb\n");
}
