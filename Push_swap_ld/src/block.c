/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:29:40 by jschille          #+#    #+#             */
/*   Updated: 2019/04/11 15:17:40 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_block		*get_last_block(t_block *block)
{
	while (block->next)
		block = block->next;
	return (block);
}

void		del_block(t_block **block)
{
	t_block	*tmp;
	t_block	*parent;

	tmp = (*block);
	parent = NULL;
	while ((*block)->next)
	{
		parent = *block;
		(*block) = (*block)->next;
	}
	free(*block);
	if (parent)
		parent->next = NULL;
	else
	{
		*block = NULL;
		return ;
	}
	(*block) = tmp;
}

int			end_block(t_block *block)
{
	if (block == NULL)
		return (0);
	while (block->next)
		block = block->next;
	return (block->count);
}

void		create_block(t_block **block, int count)
{
	t_block		*p;
	t_block		*tmp;

	tmp = (*block);
	if (!(p = (t_block*)malloc(sizeof(t_block))))
		err_out(1);
	p->count = count;
	p->next = NULL;
	if (*block == NULL)
	{
		*block = p;
		return ;
	}
	while ((*block)->next)
		(*block) = (*block)->next;
	(*block)->next = p;
	(*block) = tmp;
}

void		fix_block(t_ld_stack *stk, t_block *block, int count, int ce)
{
	t_block *tmp;
	int		i;

	tmp = get_last_block(block);
	i = -1;
	while (++i < ce)
		stk->shift_down(stk);
	tmp->count -= count;
}
