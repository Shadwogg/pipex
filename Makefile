# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:28:42 by ggiboury          #+#    #+#              #
#    Updated: 2023/02/27 13:55:25 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_GNL = get_next_line.c		\
		get_next_line_utils.c

SRC = pipex.c					\
		ft_cmd_utils.c			\
		ft_exec.c				\
		ft_free.c				\
		ft_parse.c				\
		ft_split.c				\
		ft_str_utils.c			\
		ft_write.c				\
#		$(SRC_GNL)
		


all : $(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)

clean :
	@echo "suppression"

fclean : clean
	@/bin/rm -rf $(NAME)

re : fclean $(NAME)

#bonus : re
#	@echo "salut les amis\ncomment ca va\nlol\nsalut les enn\nsalut les amis" > intest2
#	gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)
#	./pipex intest2 "grep salut" sort uniq "wc -c" outtest2
#	@make fclean

test : re
	@echo "salut les amis\n c tre le test" > intest
	./pipex intest "ls" "wc -c" outtest
#	./pipex intest "grep salut" "wc -w" outtest