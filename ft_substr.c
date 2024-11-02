/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:14:23 by marvin            #+#    #+#             */
/*   Updated: 2024/11/02 16:14:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(1 + len * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strncpy(sub, &s[start], len);
	sub[len] = 0;
	return (sub);
}
