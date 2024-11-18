/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:06:16 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/14 13:28:48 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(va_list args, char *case_type)
{
	unsigned int	value;
	int				count;

	count = 0;
	value = va_arg(args, unsigned int);
	if (ft_strncmp(case_type, "lower", ft_strlen("upper")) == 0)
		count += ft_putnbr_base((unsigned long)value, "0123456789abcdef");
	else if (ft_strncmp(case_type, "upper", ft_strlen("upper")) == 0)
		count += ft_putnbr_base((unsigned long)value, "0123456789ABCDEF");
	return (count);
}
