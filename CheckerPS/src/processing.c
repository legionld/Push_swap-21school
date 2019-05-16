/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:14:58 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 15:06:57 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ps_swap_two(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	stk_a->swap(stk_a);
	stk_b->swap(stk_b);
}

static void	ps_rotate_two(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	stk_a->shift_up(stk_a);
	stk_b->shift_up(stk_b);
}

static void	ps_rotate_r_two(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	stk_a->shift_down(stk_a);
	stk_b->shift_down(stk_b);
}

void		ps_push(t_ld_stack *stk_a, t_ld_stack *stk_b, char c)
{
	if (c == 'a')
	{
		stk_a->push(stk_a, stk_b->arr[stk_b->top]);
		stk_b->del_num(stk_b);
	}
	else
	{
		stk_b->push(stk_b, stk_a->arr[stk_a->top]);
		stk_a->del_num(stk_a);
	}
}

void		processing(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	char	*line;
	int		e;

	e = 0;
	while (get_next_line(0, &line))
	{
		ft_strcmp(line, "sa") == 0 ? stk_a->swap(stk_a) : (++e);
		ft_strcmp(line, "sb") == 0 ? stk_b->swap(stk_b) : (++e);
		ft_strcmp(line, "ss") == 0 ? ps_swap_two(stk_a, stk_b) : (++e);
		ft_strcmp(line, "pa") == 0 ? ps_push(stk_a, stk_b, 'a') : (++e);
		ft_strcmp(line, "pb") == 0 ? ps_push(stk_a, stk_b, 'b') : (++e);
		ft_strcmp(line, "ra") == 0 ? stk_a->shift_up(stk_a) : (++e);
		ft_strcmp(line, "rb") == 0 ? stk_b->shift_up(stk_b) : (++e);
		ft_strcmp(line, "rr") == 0 ? ps_rotate_two(stk_a, stk_b) : (++e);
		ft_strcmp(line, "rra") == 0 ? stk_a->shift_down(stk_a) : (++e);
		ft_strcmp(line, "rrb") == 0 ? stk_b->shift_down(stk_b) : (++e);
		ft_strcmp(line, "rrr") == 0 ? ps_rotate_r_two(stk_a, stk_b) : (++e);
		(e == 11) ? err_out(2) : (e = 0);
		if (stk_a->mod & PS_DEBUG)
			ps_writer(stk_a, stk_b);
	}
	free(line);
}
