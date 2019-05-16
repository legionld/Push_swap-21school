/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:46:19 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:28:09 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	size_t	l;

	l = 0;
	p = (char*)malloc(sizeof(char) * (int)size);
	if (p == NULL)
		return ((void*)p);
	while (size-- > 0)
		p[l++] = 0;
	return ((void*)p);
}
