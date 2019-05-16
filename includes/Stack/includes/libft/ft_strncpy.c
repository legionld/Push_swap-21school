/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:03:44 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:50:05 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		f;

	f = 0;
	i = 0;
	while (i < len)
	{
		if (src[i] == '\0' && f == 0)
			f = 1;
		if (f == 1)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		++i;
	}
	return (dst);
}
