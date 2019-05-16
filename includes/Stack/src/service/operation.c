/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:30:17 by jschille          #+#    #+#             */
/*   Updated: 2019/05/15 15:19:15 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ld_stack.h"

static int		ld_push(t_ld_stack *stack, int val)
{
	int		index;

	if ((index = stack->get_ti(stack)) == 0)
		return (0);
	if (index == -1)
		index = stack->size;
	stack->arr[index - 1] = val;
	stack->en[index - 1] = 1;
	stack->top = index - 1;
	if (stack->mod & 1)
	{
		ft_putchar('p');
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	return (1);
}

static int		ld_swap(t_ld_stack *stack)
{
	int		tmp;

	if (stack->top >= stack->size - 1)
		return (-1);
	tmp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top + 1];
	stack->arr[stack->top + 1] = tmp;
	if (stack->mod & 1)
	{
		ft_putchar('s');
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	return (0);
}

static int		ld_shift_up(t_ld_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->top == stack->size - 1)
		return (-1);
	tmp = stack->arr[stack->top];
	i = stack->top - 1;
	while (++i < stack->size - 1)
		stack->arr[i] = stack->arr[i + 1];
	stack->arr[i] = tmp;
	if (stack->mod & 1)
	{
		ft_putchar('r');
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	return (0);
}

static int		ld_shift_down(t_ld_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->top >= stack->size - 1)
		return (-1);
	tmp = stack->arr[stack->size - 1];
	i = stack->size;
	while (--i > stack->top)
		stack->arr[i] = stack->arr[i - 1];
	stack->arr[stack->top] = tmp;
	if (stack->mod & 1)
	{
		ft_putstr("rr");
		ft_putchar(stack->name);
		ft_putchar('\n');
	}
	return (0);
}

void			ld_set_operations(t_ld_stack *stack)
{
	stack->shift_up = ld_shift_up;
	stack->shift_down = ld_shift_down;
	stack->swap = ld_swap;
	stack->push = ld_push;
}
