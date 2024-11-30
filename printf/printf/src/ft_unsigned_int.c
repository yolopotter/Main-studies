/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:06:31 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/22 16:49:56 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int(va_list args)
{
	unsigned int	value;
	int				str_len;
	char			*uitoa_str;

	value = va_arg (args, unsigned int);
	uitoa_str = ft_utoa(value);
	ft_putstr(uitoa_str);
	str_len = ft_strlen(uitoa_str);
	free(uitoa_str);
	return (str_len);
}
