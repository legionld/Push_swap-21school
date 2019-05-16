/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:16:40 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 15:14:10 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ld_stack.h"

static int		ld_get_ti(t_ld_stack *stack)
{
	int		i;

	i = -1;
	while (++i < stack->size)
		if (stack->en[i] == 1)
			return (i);
	return (-1);
}

static void		print_stack(t_ld_stack *stack)
{
	int		i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->en[i] == 0)
			ft_putchar('-');
		else
			ft_putnbr(stack->arr[i]);
		ft_putchar('\n');
	}
}

static int		fill_stack(t_ld_stack *stack, int num, char name, int mod)
{
	stack->name = name;
	stack->size = num;
	stack->top = -1;
	stack->mod = mod;
	stack->print = print_stack;
	stack->get_ti = ld_get_ti;
	ld_set_operations(stack);
	ld_set_destructors(stack);
	return (1);
}

t_ld_stack		*ld_stack_init(int num, char name, int mod)
{
	t_ld_stack	*stk;
	int			i;

	if (!(stk = (t_ld_stack*)malloc(sizeof(t_ld_stack))))
		return (NULL);
	if (!(stk->arr = (int*)malloc(sizeof(int) * num)))
		return (NULL);
	if (!(stk->en = (int*)malloc(sizeof(int) * num)))
		return (NULL);
	i = -1;
	while (++i < num)
		stk->en[i] = 0;
	fill_stack(stk, num, name, mod);
	return (stk);
}
