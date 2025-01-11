/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:51:35 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/09 13:08:21 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

#endif
