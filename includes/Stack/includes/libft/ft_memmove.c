/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 07:19:43 by jschille          #+#    #+#             */
/*   Updated: 2018/12/09 12:51:02 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			d[i] = s[i];
			++i;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			--i;
			d[i] = s[i];
		}
	}
	return (dst);
}
