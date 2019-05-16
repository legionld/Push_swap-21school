/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:33:20 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 15:10:43 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ld_stack.h"

static int		ld_delete_num(t_ld_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	stack->en[stack->top] = 0;
	stack->top++;
	if (stack->top == stack->size)
		stack->top = -1;
	return (0);
}

static int		ld_delete_stack(t_ld_stack *stack)
{
	free(stack->arr);
	free(stack->en);
	free(stack);
	return (0);
}

void			ld_set_destructors(t_ld_stack *stack)
{
	stack->del_num = ld_delete_num;
	stack->del_stack = ld_delete_stack;
}
