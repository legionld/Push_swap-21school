/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:41:20 by jschille          #+#    #+#             */
/*   Updated: 2018/12/06 12:28:51 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		p[i] = f(i, s[i]);
		++i;
	}
	p[i] = '\0';
	return (p);
}
