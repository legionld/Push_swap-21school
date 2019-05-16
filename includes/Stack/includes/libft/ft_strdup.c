/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:07:53 by jschille          #+#    #+#             */
/*   Updated: 2018/11/27 19:00:18 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (p == NULL)
		return (p);
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
