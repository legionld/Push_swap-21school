# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschille <jschille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 20:36:04 by jschille          #+#    #+#              #
#    Updated: 2019/05/04 18:15:42 by jschille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_1 = CheckerPS/src/*.c
SOURCES_2 = Push_swap_ld/src/*.c srcs/parser.c

NAME_1 = checker

NAME_2 = push_swap

WWW = -Wall -Wextra -Werror -g

INCLUDES_1 = -I CheckerPS/include/ -I includes/Stack/includes/ -I includes/Stack/includes/libft/

INCLUDES_2 = -I Push_swap_ld/include/ -I includes/Stack/includes/ -I includes/Stack/includes/libft/

all: $(NAME_1)

$(NAME_1):
	make -C ./includes/Stack/includes/libft
	make -C ./includes/Stack
	gcc $(WWW) $(SOURCES_1) $(INCLUDES_1) includes/Stack/ld_stack.a -L./includes/Stack/includes/libft -lft -o $(NAME_1)
	gcc $(WWW) $(SOURCES_2) $(INCLUDES_2) includes/Stack/ld_stack.a -L./includes/Stack/includes/libft -lft -o $(NAME_2)

clean:
	make -C ./includes/Stack/includes/libft clean
	make -C ./includes/Stack clean

fclean: clean
	make -C ./includes/Stack/includes/libft fclean
	make -C ./includes/Stack fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all

main:
	rm -f $(NAME_1)
	rm -f $(NAME_2)
	gcc $(WWW) $(SOURCES_1) $(INCLUDES_1) includes/Stack/ld_stack.a -L./includes/Stack/includes/libft -lft -o $(NAME_1)
	gcc $(WWW) $(SOURCES_2) $(INCLUDES_2) includes/Stack/ld_stack.a -L./includes/Stack/includes/libft -lft -o $(NAME_2)

ps:
	gcc $(WWW) -g $(SOURCES_2) $(INCLUDES_2) includes/Stack/ld_stack.a -L./includes/Stack/includes/libft -lft -o push_swap

ck:
	gcc $(WWW) -g $(SOURCES_1) $(INCLUDES_1) includes/Stack/ld_stack.a -L./includes/Stack/includes/libft -lft -o checker