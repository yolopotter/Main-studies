/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:07:35 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/22 16:49:43 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(va_list args)
{
	char	*value;

	value = va_arg(args, char *);
	if (!value)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		ft_putstr(value);
	return (ft_strlen(value));
}
