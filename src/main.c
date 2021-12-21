/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:47:56 by iouali            #+#    #+#             */
/*   Updated: 2021/12/21 20:22:54 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_piles piles;

	if (check_arguments(argv) < 0)
		return (return_errors("Error"));
	if (argc <= 1)
		return (-1);

	init_piles(&piles, argv + 1);
	// print_debug(&piles);

	find_median(&piles);
	// print_debug(&piles);

	move_above_median_to_b(&piles);
	// print_debug(&piles);

	move_to_a(&piles);
	// print_debug(&piles);

	move_under_median_to_b(&piles);
	// print_debug(&piles);

	move_to_a(&piles);
	// print_debug(&piles);

	// swap_a(&piles);
	// print_debug(&piles);

	// rotate_a(&piles);
	// print_debug(&piles);

	// push_a(&piles);
	// print_debug(&piles);

	// rotate_a(&piles);
	// print_debug(&piles);

	// push_a(&piles);
	// print_debug(&piles);

	free(piles.tab_a);
	free(piles.tab_b);
	return (0);
}