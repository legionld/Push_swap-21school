/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:56:13 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 15:44:21 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include "../../includes/Stack/includes/ld_stack.h"
# include "../../includes/Stack/includes/libft/libft.h"
# define PS_DEBUG 2

int			err_out(int e);
char		**get_nums(char **argv, int w_count, int len, int j);
int			get_words(char **argv, int len, int *index);
void		put_numbers(t_ld_stack *stk, char **nums, int len, int j);
void		split(char *str, char ***nums);

int			ps_writer(t_ld_stack *stk_a, t_ld_stack *stk_b);
void		processing(t_ld_stack *stk_a, t_ld_stack *stk_b);

#endif
