/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:47:54 by iouali            #+#    #+#             */
/*   Updated: 2021/12/21 21:07:10 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arguments(char **numbers)
{
	int i;
	int j;

	i = 1;
	while (numbers[i])
	{
		j = 0;
		if (numbers[i][j] == '-')
			j++;
		while (numbers[i][j])
		{
			if (!ft_isdigit(numbers[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
