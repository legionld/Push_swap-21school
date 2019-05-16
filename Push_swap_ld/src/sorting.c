/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:02:00 by jschille          #+#    #+#             */
/*   Updated: 2019/05/15 16:12:32 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_med(t_ld_stack *stack, t_block *block)
{
	int		i;
	int		sum;
	int		end;
	int		count;

	sum = 0;
	i = -1;
	if (block == NULL)
		end = stack->size - 1 - stack->top;
	else
		end = end_block(block);
	count = 0;
	while (++i <= end - 1 && ++count)
		sum += stack->arr[stack->top + i];
	if (count == 0)
		return (0);
	return (sum / (count));
}

int		get_max(t_ld_stack *stk, int end)
{
	int		j;
	int		max;

	j = stk->top;
	max = j;
	while (++j < stk->top + end)
	{
		if (stk->arr[max] < stk->arr[j])
			max = j;
	}
	return (max);
}

int		get_min(t_ld_stack *stk, int end)
{
	int		j;
	int		max;

	j = stk->top;
	max = j;
	while (++j < stk->top + end)
	{
		if (stk->arr[max] > stk->arr[j])
			max = j;
	}
	return (max);
}

void	del_unit(t_sort **unit)
{
	t_block *tmp;

	while ((*unit)->block_a && (*unit)->block_a->next)
	{
		tmp = (*unit)->block_a->next;
		free((*unit)->block_a);
		(*unit)->block_a = tmp;
	}
	free((*unit)->block_a);
	while ((*unit)->block_b && (*unit)->block_b->next)
	{
		tmp = (*unit)->block_b->next;
		free((*unit)->block_b);
		(*unit)->block_b = tmp;
	}
	free((*unit)->block_b);
}

void	sort(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	t_sort	*unit;

	if (issort_block_a(stk_a, stk_a->size - 1))
		return ;
	unit = set_unit(stk_a, stk_b);
	f_move_stack(unit);
	if (stk_b->top >= 0)
		move_stack_b(unit);
	del_unit(&unit);
	free(unit);
}
