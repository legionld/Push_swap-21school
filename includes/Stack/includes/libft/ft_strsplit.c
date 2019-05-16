/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:45:52 by jschille          #+#    #+#             */
/*   Updated: 2018/12/06 13:22:47 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cw(char const *s, char c)
{
	int	i;
	int	f;
	int count;

	i = 0;
	f = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && f == 0)
			f = 1;
		if (s[i] == c && f == 1)
		{
			f = 0;
			++count;
		}
		++i;
	}
	if (f == 1)
		++count;
	return (count);
}

static int		len_n(char const *s, char c)
{
	int i;
	int	b;

	i = 0;
	while (s[i] == c)
		++i;
	b = i;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i - b);
		++i;
	}
	return (i - b);
}

static char		*fill_w(char const *s, char c)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	while (s[i] == c)
		++i;
	if (!(p = (char*)malloc(sizeof(char) * (len_n(&s[i], c) + 1))))
		return (p);
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			p[j] = '\0';
			return (p);
		}
		p[j] = s[i];
		++i;
		++j;
	}
	p[j] = '\0';
	return (p);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	char	**p;

	if (s == NULL)
		return (NULL);
	if (!(p = (char**)malloc((sizeof(char*) * (cw(s, c) + 1)))))
		return (p);
	count = 0;
	i = -1;
	if (s[0] != c)
		p[count++] = fill_w(&s[0], c);
	while (s[++i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				++i;
			p[count++] = fill_w(&s[i], c);
		}
		if (s[i] == '\0')
			break ;
	}
	p[cw(s, c)] = NULL;
	return (p);
}
