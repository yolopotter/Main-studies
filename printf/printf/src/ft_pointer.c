/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:07:25 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/22 16:46:57 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list args)
{
	void	*value;
	int		count;

	count = 0;
	value = va_arg(args, void *);
	if (value == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_putnbr_base((unsigned long)value, "0123456789abcdef");
	}
	return (count);
}
