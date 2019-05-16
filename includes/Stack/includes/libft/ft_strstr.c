/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:46:40 by jschille          #+#    #+#             */
/*   Updated: 2018/12/05 22:32:02 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	f;

	i = -1;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[++i] != '\0')
	{
		j = 0;
		f = 1;
		if (haystack[i] == needle[0])
		{
			while (needle[j] != '\0' && f != 0)
			{
				if (haystack[i + j] != needle[j])
					f = 0;
				++j;
			}
			if (f == 1)
				return ((char*)haystack + i);
		}
	}
	return (NULL);
}
