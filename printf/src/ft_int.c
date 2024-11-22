/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:07:10 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/22 16:46:16 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(va_list args)
{
	int		value;
	int		str_len;
	char	*itoa_str;

	value = va_arg(args, int);
	itoa_str = ft_itoa(value);
	ft_putstr(itoa_str);
	str_len = ft_strlen(itoa_str);
	free(itoa_str);
	return (str_len);
}
