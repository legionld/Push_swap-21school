/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:54:53 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:51:22 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*p;

	i = 0;
	p = (char*)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (p);
	while (i < size)
		p[i++] = '\0';
	p[i] = '\0';
	return (p);
}
