/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:27:54 by jschille          #+#    #+#             */
/*   Updated: 2019/04/12 03:28:12 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	write_command(void)
{
	ft_putstr("sa \t swap a - swap the first 2 elements at the top of stack a. \
Do nothing if there is only one or no elements).\n");
	ft_putstr("sb \t swap b - swap the first 2 elements at the top of stack b. \
Do nothing if there is only one or no elements).\n");
	ft_putstr("ss \t sa and sb at the same time.\n");
	ft_putstr("pa \t push a - take the first element at the top of b and put \
it at the top of a. Do nothing if b is empty.\n");
	ft_putstr("pb \t push b - take the first element at the top of a and put \
it at the top of b. Do nothing if a is empty.\n");
	ft_putstr("ra \t rotate a - shift up all elements of stack a by 1. \
The first element becomes the last one.\n");
	ft_putstr("rb \t rotate b - shift up all elements of stack b by 1. \
The first element becomes the last one.\n");
	ft_putstr("rr \t ra and rb at the same time.\n");
	ft_putstr("rra \t reverse rotate a - shift down all elements of stack a by \
1. The last element becomes the first one.\n");
	ft_putstr("rrb \t reverse rotate b - shift down all elements of stack b by \
1. The last element becomes the first one.\n");
	ft_putstr("rrr \t rra and rrb at the same time.\n");
}

static void	print_head(int *count)
{
	ft_putstr("|-----------------------|\n");
	ft_putstr("|\tStep ");
	ft_putnbr(++(*count));
	ft_putstr("\t\t|\n");
	ft_putstr("|-----------------------|\n");
	ft_putstr("\n");
}

static void	print_footer(void)
{
	ft_putstr("\n");
	ft_putstr("^\t^\n");
	ft_putstr("a\tb\n");
	ft_putstr("|----------------------|\n");
	ft_putstr("\n");
}

void		write_help(void)
{
	ft_putstr("The program takes an array of integers as arguments\n");
	ft_putstr("The program is waiting for input of instructions for \
	a sort stack\n");
	ft_putstr("Use the-v flag to visualize the execution of the program\n");
	ft_putstr("\n");
	write_command();
}

int			ps_writer(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	static int	count = 0;
	int			i;
	char		*out;

	if (!(stk_a->mod & PS_DEBUG))
		return (1);
	i = 0;
	print_head(&count);
	while (i < stk_a->size)
	{
		out = ft_itoa(stk_a->arr[i]);
		stk_a->en[i] == 1 ? ft_putstr(out) : ft_putchar('.');
		ft_putchar('\t');
		free(out);
		out = ft_itoa(stk_b->arr[i]);
		stk_b->en[i] == 1 ? ft_putstr(out) : ft_putchar('.');
		ft_putchar('\n');
		free(out);
		++i;
	}
	print_footer();
	return (i);
}
