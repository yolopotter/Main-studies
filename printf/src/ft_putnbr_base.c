/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:21 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/14 13:28:57 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char	*base)
{
	unsigned long	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base);
	if(nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += write(1, &base[nbr % base_len] ,1);
	return (count);
}
