/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:49:39 by jschille          #+#    #+#             */
/*   Updated: 2019/05/16 17:03:05 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			err_out(int e)
{
	if (e == 1)
		ft_putstr_fd("Error! Don't have memory.\n", 2);
	if (e == 2)
		ft_putstr_fd("Error! Unknow comand, restart with option -h.\n", 1);
	if (e == 3)
		ft_putstr_fd("Error! Array have equal numbers.\n", 2);
	if (e == 4)
		ft_putstr_fd("Error\n", 2);
	if (e == 5)
		ft_putstr_fd("Unknow Error\n", 2);
	exit(0);
}

static void	del_data(char **str, t_ld_stack **stk_a, t_ld_stack **stk_b)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	(*stk_a)->del_stack(*stk_a);
	(*stk_b)->del_stack(*stk_b);
}

static void	check_sort(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	int		i;

	i = -1;
	while (++i < stk_b->size)
	{
		if (stk_b->en[i] == 1)
		{
			ft_putstr_fd("KO\n", 2);
			return ;
		}
	}
	i = -1;
	while (++i < stk_a->size - 1)
	{
		if (stk_a->arr[i] > stk_a->arr[i + 1])
		{
			ft_putstr_fd("KO\n", 2);
			return ;
		}
	}
	ft_putstr_fd("OK\n", 2);
}

int			main(int argc, char **argv)
{
	t_ld_stack	*stack_a;
	t_ld_stack	*stack_b;
	int			words;
	char		**numbers;
	int			i;

	if (argc == 1)
		exit(0);
	i = 0;
	words = get_words(argv, argc, &i);
	stack_a = ld_stack_init(words, 'a', i == 0 ? 4 : 2);
	stack_b = ld_stack_init(words, 'b', i == 0 ? 4 : 2);
	numbers = get_nums(argv, words, argc, i);
	put_numbers(stack_a, numbers, words, i);
	processing(stack_a, stack_b);
	check_sort(stack_a, stack_b);
	del_data(numbers, &stack_a, &stack_b);
	exit(0);
}
