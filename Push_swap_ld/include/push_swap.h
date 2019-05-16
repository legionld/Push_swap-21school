/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:12:06 by jschille          #+#    #+#             */
/*   Updated: 2019/05/04 15:53:14 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../includes/Stack/includes/ld_stack.h"
# include "../../includes/Stack/includes/libft/libft.h"

typedef struct s_block	t_block;

struct					s_block
{
	int			count;
	t_block		*next;
};

typedef struct			s_sort
{
	t_ld_stack	*stk_a;
	t_ld_stack	*stk_b;
	t_block		*block_a;
	t_block		*block_b;
}						t_sort;

int						err_out(int e);
int						get_words(char **argv, int len);
char					**get_nums(char **argv, int w_count, int len);
void					put_numbers(t_ld_stack *stk, char **nums, int len);
void					split(char *str, char ***nums);
void					sort(t_ld_stack *stk_a, t_ld_stack *stk_b);
t_sort					*set_unit(t_ld_stack *stk_a, t_ld_stack *stk_b);
int						get_med(t_ld_stack *stack, t_block *block);

int						f_move_stack(t_sort *unit);
int						move_stack_b(t_sort *unit);
int						move_stack_a(t_sort *unit);
void					sort_des_a(t_ld_stack *stk, int end);
void					sort_des_b(t_ld_stack *stk, int end);

t_block					*get_last_block(t_block *block);
void					del_block(t_block **block);
int						end_block(t_block *block);
void					create_block(t_block **block, int count);
void					fix_block(t_ld_stack *stk, t_block *block,
						int count, int ce);
int						count_blocks(t_block *block);

int						issort_stack(t_ld_stack *stack);
int						issort_block_a(t_ld_stack *stk, int count);
int						issort_block_b(t_ld_stack *stk, int count);

void					st_b(t_sort *unit, int end);
int						move_b(t_sort *unit, int *count, int end, int ce);
void					st_a(t_sort *unit, int end);
int						move_a(t_sort *unit, int *count, int end, int ce);
void					move_a_test(t_sort *unit, int *count, int end);
void					move_b_test(t_sort *unit, int *count, int end);

#endif
