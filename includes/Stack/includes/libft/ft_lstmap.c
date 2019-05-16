/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:35:54 by jschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:06:24 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*res;

	if (lst == NULL || f == NULL)
		return (NULL);
	p = f(lst);
	res = p;
	while (lst->next != NULL)
	{
		p->next = f(lst->next);
		if ((p = p->next) == NULL)
			return (res);
		lst = lst->next;
	}
	p->next = NULL;
	return (res);
}
