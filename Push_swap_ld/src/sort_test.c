/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:13:24 by jschille          #+#    #+#             */
/*   Updated: 2019/04/11 15:15:53 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_test(t_sort *unit, int *count, int end)
{
	int		med;
	int		i;

	i = -1;
	med = get_med(unit->stk_b, unit->block_b);
	while (++i < end)
	{
		if (unit->stk_b->arr[unit->stk_b->top + i] > med)
			++(*count);
	}
}

void	move_a_test(t_sort *unit, int *count, int end)
{
	int		med;
	int		i;

	i = -1;
	med = get_med(unit->stk_a, unit->block_a);
	while (++i < end)
	{
		if (unit->stk_a->arr[unit->stk_a->top + i] < med)
			++(*count);
	}
}
