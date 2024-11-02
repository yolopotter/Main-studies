/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:45:46 by marvin            #+#    #+#             */
/*   Updated: 2024/11/02 13:45:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dst;
	size_t len;
	int i;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
