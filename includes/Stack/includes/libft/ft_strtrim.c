/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:27:42 by jschille          #+#    #+#             */
/*   Updated: 2018/12/06 12:36:33 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace_m(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	strspcut(char const *s)
{
	int	i;
	int	f;
	int	e;

	i = 0;
	f = 0;
	while (s[i] != '\0')
	{
		if (isspace_m(s[i]) && f == 1)
		{
			e = i - 1;
			f = 0;
		}
		if (isspace_m(s[i]) == 0 && f == 0)
			f = 1;
		++i;
	}
	if (f == 1)
		e = i - 1;
	return (e);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	b;
	unsigned int	e;
	char			*p;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (isspace_m(s[i]))
		++i;
	b = i;
	e = strspcut(s);
	p = (char *)malloc(sizeof(char) * (e - b + 2));
	if (p == NULL)
		return (p);
	i = 0;
	while (i < e - b + 1 && s[i + b] != '\0')
	{
		p[i] = s[i + b];
		++i;
	}
	p[i] = '\0';
	return (p);
}
