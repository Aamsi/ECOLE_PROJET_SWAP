/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:47:11 by iouali            #+#    #+#             */
/*   Updated: 2021/12/21 20:16:44 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_piles
{
	int	*tab_a;
	int	*tab_b;
	int	len_a;
	int	len_b;
	int median;
}				t_piles;


int		check_arguments(char **numbers);
void	write_string(char *s);
int		return_errors(char *error);
int		init_piles(t_piles *piles, char **args);
int		get_len(char **s);
int		get_abs(int nb);
void	swap_a(t_piles *piles);
void	swap_b(t_piles *piles);
void	swap_swap(t_piles *piles);
void	push_b(t_piles *piles);
void	push_a(t_piles *piles);
void	rotate_a(t_piles *piles);
void	rotate_b(t_piles *piles);
void	reverse_rotate_a(t_piles *piles);
void	reverse_rotate_b(t_piles *piles);
void	reverse_rotate_rotate(t_piles *piles);
void	find_median(t_piles *piles);
void	move_under_median_to_b(t_piles *piles);
void	move_above_median_to_b(t_piles *piles);
void	move_to_a(t_piles *piles);


// DEBUG
void    print_debug(t_piles *piles);

#endif