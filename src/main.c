/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:47:56 by iouali            #+#    #+#             */
/*   Updated: 2021/12/25 17:48:40 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_piles piles;

	if (argc <= 1)
		return (-1);
	if (check_arguments(argv) < 0)
		return (return_errors("Error"));

	init_piles(&piles, argv + 1);
	find_median(&piles);
	route_algo(&piles);
	free(piles.tab_a);
	free(piles.tab_b);
	return (0);
}
