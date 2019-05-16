/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:51:59 by jschille          #+#    #+#             */
/*   Updated: 2019/04/11 15:11:39 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a(t_ld_stack *stk)
{
	stk->swap(stk);
	stk->shift_up(stk);
	stk->swap(stk);
	stk->shift_down(stk);
}

static void	swap_b(t_ld_stack *stk)
{
	stk->shift_up(stk);
	stk->swap(stk);
	stk->shift_down(stk);
}

static void	srtdes(t_ld_stack *stk)
{
	if (stk->arr[stk->top] < stk->arr[stk->top + 1])
	{
		if (stk->arr[stk->top + 1] < stk->arr[stk->top + 2])
		{
			swap_a(stk);
			stk->swap(stk);
		}
		else if (stk->arr[stk->top] < stk->arr[stk->top + 2])
			swap_a(stk);
		else
			stk->swap(stk);
	}
	else if (stk->arr[stk->top + 1] < stk->arr[stk->top + 2])
	{
		if (stk->arr[stk->top] < stk->arr[stk->top + 2])
		{
			swap_b(stk);
			stk->swap(stk);
		}
		else
			swap_b(stk);
	}
}

void		sort_des_b(t_ld_stack *stk, int end)
{
	if (end == 3)
		srtdes(stk);
	if (end == 2)
		if (stk->arr[stk->top] < stk->arr[stk->top + 1])
			stk->swap(stk);
}
