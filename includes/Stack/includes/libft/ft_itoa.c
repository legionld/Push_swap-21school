/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:29:42 by jschille          #+#    #+#             */
/*   Updated: 2018/12/01 12:01:27 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long n)
{
	if (n < 10)
		return (1);
	return (1 + nbrlen(n / 10));
}

static int	pow_n(int a, int b)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i < b)
	{
		res *= a;
		++i;
	}
	return (res);
}

char		*ft_itoa(int nb)
{
	char	*p;
	int		len;
	int		i;
	long	n;

	n = nb;
	i = 0;
	if (n < 0)
	{
		++i;
		n *= (-1);
	}
	len = nbrlen(n) + i;
	if (!(p = (char*)malloc(sizeof(char) * (len + 1))))
		return (p);
	if (i > 0)
		p[0] = '-';
	while (i < len)
	{
		p[i] = n / pow_n(10, len - i - 1) + '0';
		n %= pow_n(10, len - i - 1);
		++i;
	}
	p[i] = '\0';
	return (p);
}
