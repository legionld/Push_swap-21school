/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:49:09 by jschille          #+#    #+#             */
/*   Updated: 2019/04/11 15:17:46 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		issort_stack(t_ld_stack *stack)
{
	int		i;

	i = -1;
	while (++i < stack->size - 1)
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
	return (1);
}

int		issort_block_a(t_ld_stack *stk, int count)
{
	int		i;
	int		beg;

	i = -1;
	beg = stk->top;
	while (++i < count)
		if (stk->arr[beg + i] > stk->arr[beg + i + 1])
			return (0);
	return (1);
}

int		issort_block_b(t_ld_stack *stk, int count)
{
	int		i;
	int		beg;

	i = -1;
	beg = stk->top;
	while (++i < count)
		if (stk->arr[beg + i] < stk->arr[beg + 1 + i])
			return (0);
	return (1);
}
