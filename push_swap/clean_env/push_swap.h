/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:51:35 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 14:15:17 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_calc
{
	int	price;
	int	cheapest;
	int	cheapest_number;
	int	current_nb;
	int	position;
	int	ra;
	int	rb;
}	t_calc;

//parse
int		*parsing(int ac, char **av);
int		*normalize_sequence(int *src, int len);

//parse single ac
int		arr_len(char *arr);
int		*extract_single(char *arr);
int		validate_input_single(char *str);

//parse multiple ac's
int		validate_input_multiple(char **av);
int		*extract_multiple(int ac, char **av);

//parse utils
int		ft_atoi_error(char *str, int *i, int *error);
int		is_num(char c);
int		is_space(char c);
int		check_repeat(int *arr, int len);
int		check_overflow(int sign, long int res, int *error);

//action
void	rotate(int ra, int rb, int *stack_a, int *stack_b);
void	move_all_to_other(int *stack_a, int *stack_b);

//operators
int		apply_swap(int *src);
int		apply_push(int *dst, int *src);
int		apply_reverse_rotation(int *stack);
int		apply_rotation(int *stack);

//utils
int		stack_len(int *stack);
int		find_max(int *stack);
int		find_min(int *stack);
int		is_sorted(int *stack);
int		find_gap(int nb, int *stack);

//calc
int		calc_rotation_or_reverse(int pos, int *stack);
int		calc_find_smallest_current(int c_max, int *i, int *stack_a);
int		calc_price(int ra, int rb);
int		calc_find_cheapest_nb(int c_max, int *stack_a, int *stack_b);

//calc utils
int		calc_find_current_position(int current, int *stack_a);
int		ft_abs(int a);
int		ft_min(int a, int b);

//algos
int		size_mini_under_3(int amount, int *stack);
int		size_mini_algorithm(int amount, int *stack);
int		size_small_algorithm(int *stack_a, int *stack_b);
int		size_big_algorithm(int amount, int *stack_a, int *stack_b);

#endif
