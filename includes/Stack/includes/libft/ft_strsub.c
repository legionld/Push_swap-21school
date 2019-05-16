/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:26:07 by jschille          #+#    #+#             */
/*   Updated: 2018/12/09 12:52:10 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*p;

	i = 0;
	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (p);
	while (i < len)
	{
		if (s[start] == '\0')
			return (NULL);
		p[i] = s[start++];
		++i;
	}
	p[i] = '\0';
	return (p);
}
