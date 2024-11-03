/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:10:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/03 13:10:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
//#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		match_flag;
	int		start_flag;
	int		end_flag;
	size_t	len;
	char	*dst;

	if (s1 == NULL || set == NULL)
		return (NULL);

	len = strlen(s1);
	i = 0;
	start_flag = -1;

	//find start of str
	while (s1[i])
	{
		j = 0;
		match_flag = 0;
		while (set[j])
		{
			if (strncmp(&s1[i], &set[j], 1) == 0)
				match_flag = 1;
			j++;
		}
		if (match_flag == 0)
		{
			start_flag = i;
			break;
		}
		i++;
	}
	//find end of str
	while (len > start_flag)
	{
		j = 0;
		match_flag = 0;
		while (set[j])
		{
			if (strncmp(&s1[len], &set[j], 1) == 0)
				match_flag = 1;
			j++;
		}
		if (match_flag == 0)
		{
			end_flag = len;
			break;
		}
		len--;
	}
 /*
	dst = (char *)ft_calloc(1 + len, sizeof(char));
	if (!dst)
		return (NULL);
	dst = ft_strcat(dst, s1);
	return (dst);
*/
}

int main()
{
	ft_strtrim("--_a", "-");
	return 0;
}
