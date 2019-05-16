/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:05:15 by jschille          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:57 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	if (!(p = (t_list*)malloc(sizeof(t_list))))
		return (p);
	if (content_size != 0 && content != NULL)
	{
		p->content = malloc(content_size);
		p->content = ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	else
	{
		if (content != NULL)
			p->content_size = content_size;
		else
			p->content_size = 0;
		p->content = NULL;
	}
	p->next = NULL;
	return (p);
}
