/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:34:19 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/22 16:49:02 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_identifier(va_list args, char a)
{
	int	c;

	c = 0;
	if (a == 'c')
		c += ft_char(args);
	else if (a == 's')
		c += ft_string(args);
	else if (a == 'p')
		c += ft_pointer(args);
	else if (a == 'd' || a == 'i')
		c += ft_int(args);
	else if (a == 'u')
		c += ft_unsigned_int(args);
	else if (a == 'x')
		c += ft_hex(args, "lower");
	else if (a == 'X')
		c += ft_hex(args, "upper");
	else if (a == '%')
		c += write(1, "%", 1);
	return (c);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			c;

	va_start (args, s);
	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '%' && (!strchr("cspdiuxX%", s[i + 1]) || s[i + 1] == '\0'))
			return (-1);
		if (s[i] == '%' && strchr("cspdiuxX%", s[i + 1]))
		{
			c += is_identifier(args, s[i + 1]);
			i++;
		}
		else
			c += write(1, &s[i], 1);
		i++;
	}
	va_end (args);
	return (c);
}
