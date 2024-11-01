/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:01:27 by marvin            #+#    #+#             */
/*   Updated: 2024/11/01 14:01:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while(big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while((big[i + j] == little[j]) && big[i + j] && little[j])
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
