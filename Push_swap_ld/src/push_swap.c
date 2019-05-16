/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:33:42 by jschille          #+#    #+#             */
/*   Updated: 2019/05/15 16:54:03 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		err_out(int e)
{
	if (e == 1)
		ft_putstr_fd("Error! Don't have memory.\n", 2);
	if (e == 2)
	{
		ft_putstr_fd("Warning! Unknow comand, restart with option -h.\n", 1);
		return (0);
	}
	if (e == 3)
		ft_putstr_fd("Error! Array have equal numbers.\n", 2);
	if (e == 4)
		ft_putstr_fd("Error\n", 2);
	if (e == 5)
		ft_putstr_fd("Unknow Error\n", 2);
	exit(0);
}

void	del_data(char **str, t_ld_stack **stk_a, t_ld_stack **stk_b)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		++i;
	}
	free(str);
	(*stk_a)->del_stack(*stk_a);
	(*stk_b)->del_stack(*stk_b);
}

void	sort_three(t_ld_stack *stk_a)
{
	if (stk_a->arr[0] > stk_a->arr[1])
	{
		if (stk_a->arr[1] > stk_a->arr[2])
		{
			stk_a->shift_up(stk_a);
			stk_a->swap(stk_a);
		}
		else if (stk_a->arr[0] > stk_a->arr[2])
			stk_a->shift_up(stk_a);
		else
			stk_a->swap(stk_a);
	}
	else if (stk_a->arr[1] > stk_a->arr[2])
	{
		if (stk_a->arr[0] > stk_a->arr[2])
			stk_a->shift_down(stk_a);
		else
		{
			stk_a->shift_down(stk_a);
			stk_a->swap(stk_a);
		}
	}
}

int		main(int argc, char **argv)
{
	t_ld_stack	*stack_a;
	t_ld_stack	*stack_b;
	int			words;
	char		**numbers;

	words = get_words(argv, argc);
	stack_a = ld_stack_init(words, 'a', 0);
	stack_b = ld_stack_init(words, 'b', 0);
	numbers = get_nums(argv, words, argc);
	put_numbers(stack_a, numbers, words);
	stack_a->mod = 1;
	stack_b->mod = 1;
	if (stack_a->size == 3)
		sort_three(stack_a);
	else
		sort(stack_a, stack_b);
	del_data(numbers, &stack_a, &stack_b);
	exit(0);
}
