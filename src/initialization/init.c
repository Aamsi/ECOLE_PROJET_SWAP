/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:36:23 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 17:57:37 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_tab(t_piles *piles, char **args)
{
	int	i;
	int	nb;

	i = 0;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		piles->tab_a[i] = nb;
		i++;
	}
	return (i);
}

int	init_piles(t_piles *piles, char **args)
{
	piles->tab_a = malloc(sizeof(int) * get_len(args));
	if (!piles->tab_a)
		return (-1);
	piles->len_a = fill_tab(piles, args);
	piles->tab_b = 0;
	piles->len_b = 0;
	piles->median = 0;
	piles->q1 = 0;
	piles->q2 = 0;
	piles->q3 = 0;
	piles->q4 = 0;
	piles->q5 = 0;
	return (0);
}
