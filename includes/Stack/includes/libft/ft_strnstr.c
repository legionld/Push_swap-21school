/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:29:35 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:52:24 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (nd[i] == '\0')
		return ((char*)hs);
	if (len < ft_strlen(nd))
		return (NULL);
	while (i < len && hs[i] != '\0')
	{
		j = 0;
		if (hs[i] == nd[0])
		{
			while (j < ft_strlen(nd))
			{
				if (hs[i + j] != nd[j] || (i + j) >= len)
					break ;
				++j;
			}
			if ((j == len && j < ft_strlen(nd)) || nd[j] == '\0')
				return ((char*)hs + i);
		}
		++i;
	}
	return (NULL);
}
