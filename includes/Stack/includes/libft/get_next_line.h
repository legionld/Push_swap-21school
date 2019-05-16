/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:19:36 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/01/11 18:17:08 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# define BUFF_SIZE 5
# define NEXT(y) if ((y) == 1) {free(buff); return (1);}
# define ERR_OUT(y) if (!(y)) return (-1);
# define CHECK if (*line[0] != '\0') return (1);

int get_next_line(const int fd, char **line);

#endif
