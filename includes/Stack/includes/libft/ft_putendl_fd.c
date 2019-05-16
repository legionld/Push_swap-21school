/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:41:47 by jschille          #+#    #+#             */
/*   Updated: 2018/12/06 12:52:48 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	if (fd <= 0 || s == NULL)
		return ;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
