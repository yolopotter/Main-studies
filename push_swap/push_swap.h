/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:51:35 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/28 12:51:35 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h> // NULL
# include <stdio.h> // printf

int	stack_len(int *stack);
int	apply_push(int *dst, int *src);
int	apply_reverse_rotation(int *stack);
int	apply_rotation(int *stack);

#endif
