/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:31:53 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:59:18 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			a = s1[i];
			b = s2[i];
			return (a - b);
		}
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			return (a - b);
		}
		++i;
	}
	return (0);
}
