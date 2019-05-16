/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:50:51 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 18:25:00 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				f_move_stack(t_sort *unit)
{
	int		i;
	int		count;
	int		med;

	i = unit->stk_a->top - 1;
	med = get_med(unit->stk_a, unit->block_a);
	count = 0;
	while (++i < unit->stk_a->size && unit->stk_a->top < unit->stk_a->size - 3)
	{
		if (unit->stk_a->arr[unit->stk_a->top] < med)
		{
			++count;
			unit->stk_b->push(unit->stk_b, unit->stk_a->arr[unit->stk_a->top]);
			unit->stk_a->del_num(unit->stk_a);
		}
		else
			unit->stk_a->shift_up(unit->stk_a);
	}
	if (count != 0)
		create_block(&(unit->block_b), count);
	if (unit->stk_a->top < unit->stk_a->size - 3)
		f_move_stack(unit);
	sort_des_a(unit->stk_a, unit->stk_a->size - unit->stk_a->top);
	return (1);
}

static void		move_supp_a(t_sort *unit, int count, int ce)
{
	int	end;

	create_block(&(unit->block_b), count);
	fix_block(unit->stk_a, unit->block_a, count, ce);
	if (!issort_block_a(unit->stk_a, end_block(unit->block_a)))
		move_stack_a(unit);
	end = end_block(get_last_block(unit->block_b));
	if (end != 0 && !issort_block_b(unit->stk_b, end))
		move_stack_b(unit);
}

int				move_stack_a(t_sort *unit)
{
	int			end;
	int			count;
	int			ce;

	if ((end = end_block(unit->block_a)) <= 3)
	{
		if (end == 0)
			return (1);
		st_a(unit, end);
		if (count_blocks(unit->block_a) == 0)
			return (1);
	}
	count = 0;
	ce = 0;
	move_a_test(unit, &ce, end);
	ce = move_a(unit, &count, end, ce);
	move_supp_a(unit, count, ce);
	move_stack_a(unit);
	return (1);
}

static void		move_supp_b(t_sort *unit, int count, int ce)
{
	create_block(&(unit->block_a), count);
	fix_block(unit->stk_b, unit->block_b, count, ce);
	if (!issort_block_b(unit->stk_b, end_block(unit->block_b)))
		move_stack_b(unit);
	if (count_blocks(unit->block_a) > 0)
		move_stack_a(unit);
}

int				move_stack_b(t_sort *unit)
{
	int			end;
	int			count;
	int			ce;

	if ((end = end_block(unit->block_b)) <= 3)
	{
		st_b(unit, end);
		return (1);
	}
	count = 0;
	ce = 0;
	move_b_test(unit, &ce, end);
	ce = move_b(unit, &count, end, ce);
	move_supp_b(unit, count, ce);
	move_stack_b(unit);
	return (1);
}
