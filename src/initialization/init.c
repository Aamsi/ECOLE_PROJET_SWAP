/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:36:23 by iouali            #+#    #+#             */
/*   Updated: 2021/12/22 18:27:22 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_piles(t_piles *piles, char **args)
{
	int i;
	int nb;

	piles->tab_a = malloc(sizeof(int) * get_len(args));
	if (!piles->tab_a)
		return (-1);
	i = 0;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		piles->tab_a[i] = nb;
		i++;
	}
	piles->len_a = i;
	piles->tab_b = 0;
	piles->len_b = 0;
	piles->median = 0;
	piles->under_500 = 0;
	piles->under_five = 0;
	piles->q1 = 0;
	piles->q2 = 0;
	piles->q3 = 0;
	piles->q4 = 0;
	piles->q5 = 0;
	if (get_len(args) <= 5)
		piles->under_five = 1;
	return (0);
}
