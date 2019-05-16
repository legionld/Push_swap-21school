/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:50:12 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:48:51 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;

	i = 0;
	len_d = 0;
	while (len_d < size && dst[len_d])
		++len_d;
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (len_d < size - 1 && src[i] != '\0')
	{
		dst[len_d++] = src[i++];
	}
	dst[len_d] = '\0';
	while (src[i++] != '\0')
		len_d++;
	return (len_d);
}
