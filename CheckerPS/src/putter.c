/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:38:14 by jschille          #+#    #+#             */
/*   Updated: 2019/05/16 17:03:50 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		put_numbers(t_ld_stack *stk, char **nums, int len, int j)
{
	int					i;
	long long int		x;

	i = len;
	while (--i >= j)
	{
		x = ft_atoi(nums[i]);
		if (x > 2147483647 || x < -2147483648 || ft_strlen(nums[i]) > 11)
			err_out(4);
		stk->push(stk, x);
	}
	i = -1;
	while (stk->arr[++i])
	{
		x = i;
		while (++x < stk->size)
			if (stk->arr[i] == stk->arr[x])
				err_out(3);
	}
}

char		**get_nums(char **argv, int w_count, int len, int j)
{
	char	**nums;
	int		i;

	i = -1;
	if (!(nums = (char**)malloc(sizeof(char*) * (w_count + 1))))
		return (NULL);
	while (++i < w_count)
	{
		if (!(nums[i] = (char*)malloc(sizeof(char) * 11)))
			return (NULL);
		ft_memset(nums[i], '\0', 10);
	}
	nums[i] = NULL;
	i = j;
	while (++i < len)
		split(argv[i], &nums);
	return (nums);
}
