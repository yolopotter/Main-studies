/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:53:59 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/13 18:20:58 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*special_case(void)
{
	char	*arr;
	int		i;
	char	*nbr;

	nbr = "-2147483648";
	arr = malloc(12 * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (nbr[i])
	{
		arr[i] = nbr[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

static	int	lenint(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len += 1;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static	int	sign_conversion(int n, int *sign)
{
	if (n < 0)
	{
		*sign = -1;
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	if (n == -2147483648)
	{
		str = special_case();
		return (str);
	}
	len = lenint(n);
	str = (char *)malloc(1 + len * sizeof(char));
	if (!str)
		return (NULL);
	sign = 1;
	n = sign_conversion(n, &sign);
	str[len] = 0;
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
