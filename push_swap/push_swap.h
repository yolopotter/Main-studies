/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:51:35 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 15:10:20 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // NULL
# include <stdio.h> // printf
# include <unistd.h> //write
# include <math.h> //min
# include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

//parse
int	arr_len(char *arr);
int *parse_single(char *arr);
int	validate_input_single(char *str);
int	is_space(char c);
int check_overflow(int sign, long int res, int *error);
int	ft_atoi(char *str, int *i, int *error);
int	is_num(char c);
int	validate_input_multiple(char **av);
int	*parsing(int ac, char **av);
int	validate_input_multiple(char **av);
int	*parse_multiple(int ac, char **av);
int	*normalize_sequence(int *src, int len);
int	check_repeat(int *arr, int len);

//action
int	rotate(int ra, int rb, int *stack_A, int *stack_B);
int	move_all_to_other(int *dst, int *src);

//operators
int	apply_swap(int *src);
int	apply_push(int *dst, int *src);
int	apply_reverse_rotation(int *stack);
int	apply_rotation(int *stack);

//utils
int	stack_len(int *stack);
int	find_max(int *stack);
int	find_min(int *stack);
int	is_sorted(int *stack);
int	find_gap(int nb, int *stack_B);

//calc
int	CALCULATE_find_current_position(int current, int *stack_A);
int	CALCULATE_rotation_or_reverse(int pos, int *stack);
int	CALCULATE_find_smallest_current(int c_min, int c_max, int *i, int *stack_A);
int	CALCULATE_price(int ra, int rb);
int	CALCULATE_find_cheapest_nb(int c_min, int c_max, int *stack_A, int *stack_B);

//algos
int	size_mini_under_3(int amount, int *stack);
int	size_mini_algorithm(int amount, int *stack);
int	size_small_algorithm(int *stack_A, int *stack_B);
int	size_big_algorithm(int amount, int *stack_A, int *stack_B);

#endif
