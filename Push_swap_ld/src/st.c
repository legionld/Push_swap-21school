/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:45 by jschille          #+#    #+#             */
/*   Updated: 2019/05/15 15:10:12 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_b(t_sort *unit, int end)
{
	int		i;

	sort_des_b(unit->stk_b, end);
	i = -1;
	if (count_blocks(unit->block_a) >= 1)
		return ;
	while (++i < end)
	{
		unit->stk_a->push(unit->stk_a, unit->stk_b->arr[unit->stk_b->top]);
		unit->stk_b->del_num(unit->stk_b);
	}
	if (unit->block_b->next != NULL)
	{
		del_block(&(unit->block_b));
		if (count_blocks(unit->block_a) > 0)
			move_stack_a(unit);
		else
			move_stack_b(unit);
	}
}

int		move_b(t_sort *unit, int *count, int end, int ce)
{
	int		med;
	int		i;

	i = -1;
	med = get_med(unit->stk_b, unit->block_b);
	while (++i < end)
	{
		if (unit->stk_b->arr[unit->stk_b->top] > med)
		{
			++(*count);
			unit->stk_a->push(unit->stk_a, unit->stk_b->arr[unit->stk_b->top]);
			unit->stk_b->del_num(unit->stk_b);
		}
		else
			unit->stk_b->shift_up(unit->stk_b);
		if ((*count) == ce)
			return (i - (*count) + 1);
	}
	return (i - (*count));
}

void	st_a(t_sort *unit, int end)
{
	int		i;

	sort_des_a(unit->stk_a, end);
	if (issort_block_a(unit->stk_a, end) == 1
		&& count_blocks(unit->block_a) <= 1)
	{
		del_block(&(unit->block_a));
		return ;
	}
	i = -1;
	while (++i < end)
	{
		unit->stk_b->push(unit->stk_b, unit->stk_a->arr[unit->stk_a->top]);
		unit->stk_a->del_num(unit->stk_a);
	}
	if (unit->block_a->next != NULL)
	{
		del_block(&(unit->block_a));
		create_block(&(unit->block_b), i);
		move_stack_a(unit);
	}
}

int		move_a(t_sort *unit, int *count, int end, int ce)
{
	int		med;
	int		i;
	int		c;

	i = -1;
	c = 0;
	med = get_med(unit->stk_a, unit->block_a);
	while (++i < end)
	{
		if (unit->stk_a->arr[unit->stk_a->top] < med)
		{
			++(*count);
			unit->stk_b->push(unit->stk_b, unit->stk_a->arr[unit->stk_a->top]);
			unit->stk_a->del_num(unit->stk_a);
		}
		else
		{
			++c;
			unit->stk_a->shift_up(unit->stk_a);
		}
		if ((*count) == ce)
			return (c);
	}
	return (c);
}

int		count_blocks(t_block *block)
{
	int		count;

	count = 0;
	if (block)
		++count;
	else
		return (0);
	while (block->next)
	{
		++count;
		block = block->next;
	}
	return (count);
}
