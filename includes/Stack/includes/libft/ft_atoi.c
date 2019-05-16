/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:49:17 by jschille          #+#    #+#             */
/*   Updated: 2019/05/16 17:04:27 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				my_isp(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static long long int	check_error(const char *str, int i, int f)
{
	int			count;
	long int	res;

	count = 0;
	res = 0;
	while ((int)str[i] >= 48 && (int)str[i] <= 57)
	{
		if (++count > 20 && f == -1)
			return (0);
		if (count >= 20 && f == 1)
			return (-1);
		else
			res = res * 10 + (int)str[i++] - 48;
	}
	return (res * f);
}

long long int			ft_atoi(const char *str)
{
	int	f;
	int	i;

	f = 1;
	i = 0;
	while (ft_isspace(str[i]) || my_isp(str[i]))
	{
		if (my_isp(str[i]))
		{
			f = my_isp(str[i++]);
			break ;
		}
		++i;
	}
	while (str[i] == '0')
		++i;
	return (check_error(str, i, f));
}
