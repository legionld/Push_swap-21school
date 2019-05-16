/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:38:14 by jschille          #+#    #+#             */
/*   Updated: 2019/04/12 06:28:31 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_numbers(t_ld_stack *stk, char **nums, int len)
{
	int		i;

	i = len;
	while (--i >= 0)
		stk->push(stk, ft_atoi(nums[i]));
}

char		**get_nums(char **argv, int w_count, int len)
{
	char	**nums;
	int		i;

	i = -1;
	if (!(nums = (char**)malloc(sizeof(char*) * (w_count + 1))))
		err_out(2);
	while (++i < w_count)
	{
		if (!(nums[i] = (char*)malloc(sizeof(char) * 11)))
			err_out(2);
		ft_memset(nums[i], '\0', 11);
	}
	nums[i] = NULL;
	i = 0;
	while (++i < len)
		split(argv[i], &nums);
	return (nums);
}
