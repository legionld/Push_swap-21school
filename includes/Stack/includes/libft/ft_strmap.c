/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:29:16 by jschille          #+#    #+#             */
/*   Updated: 2018/12/06 12:27:45 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	p = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (p == NULL)
		return (p);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = f(s[i]);
		++i;
	}
	p[i] = '\0';
	return (p);
}
