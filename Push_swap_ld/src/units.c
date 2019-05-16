/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:24:31 by jschille          #+#    #+#             */
/*   Updated: 2019/04/11 15:17:05 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort		*set_unit(t_ld_stack *stk_a, t_ld_stack *stk_b)
{
	t_sort	*p;

	if (!(p = (t_sort*)malloc(sizeof(t_sort))))
		err_out(1);
	p->stk_a = stk_a;
	p->stk_b = stk_b;
	p->block_a = NULL;
	p->block_b = NULL;
	return (p);
}
