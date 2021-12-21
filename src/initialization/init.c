/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:36:23 by iouali            #+#    #+#             */
/*   Updated: 2021/12/20 21:15:48 by iouali           ###   ########.fr       */
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
	return (0);
}
