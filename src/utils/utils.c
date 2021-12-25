/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:51:43 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 17:55:14 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_character(char c)
{
	write(1, &c, 1);
}

void	write_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write_character(s[i]);
		i++;
	}
}

int	get_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
