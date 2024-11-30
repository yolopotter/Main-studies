/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:03:16 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/18 10:32:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	lenint(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = lenint(n);
	str = (char *)malloc(1 + len * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
