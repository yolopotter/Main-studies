/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:51:35 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 13:20:39 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // NULL
# include <stdio.h> // printf
# include <unistd.h> //write
# include <math.h> //min
# include <limits.h>
// # include "parse.h"
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
// int	stack_len(int *stack);
// int	apply_push(int *dst, int *src);
// int	apply_reverse_rotation(int *stack);
// int	apply_rotation(int *stack);

#endif
