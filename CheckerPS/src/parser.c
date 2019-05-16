/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:47:16 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 15:05:35 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		split(char *str, char ***nums)
{
	static int	j = -1;
	int			i;
	int			in;

	i = -1;
	while (str[++i])
	{
		in = 0;
		if (ft_isdigit((int)str[i]) || str[i] == '-')
		{
			++j;
			while (ft_isdigit(str[i]) || str[i] == '-')
			{
				if (str[i] == '-' && in != 0)
					err_out(2);
				(*nums)[j][in] = str[i];
				++in;
				++i;
			}
		}
		if (str[i] == '\0')
			return ;
	}
}

int			split_nums(char *str)
{
	int		i;
	int		f;
	int		w_count;

	i = -1;
	f = 0;
	w_count = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '\0'
			&& str[i] != ' ')
			err_out(5);
		if (str[i] == ' ' && f == 1)
		{
			f = 0;
			++w_count;
		}
		if ((ft_isdigit((int)str[i]) || str[i] == '-') && f == 0)
			f = 1;
	}
	if (f == 1)
		++w_count;
	return (w_count);
}

int			get_words(char **argv, int len, int *index)
{
	int		i;
	int		w_count;

	if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'v')
	{
		*index = 1;
		i = 1;
	}
	i = 0;
	w_count = 0;
	while (++i < len)
		w_count += split_nums(argv[i]);
	return (w_count);
}
