# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:28:42 by ggiboury          #+#    #+#              #
#    Updated: 2023/06/07 17:08:40 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = pipex.c					\
		ft_cmd_utils.c			\
		ft_exec.c				\
		ft_free.c				\
		ft_parse.c				\
		ft_utils.c				\
		pipes.c

SRCS_BONUS = pipex_bonus.c		\
		ft_cmd_utils.c			\
		ft_exec.c				\
		ft_free.c				\
		ft_parse.c				\
		ft_utils.c				\
		pipes.c


OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)


LIBFT_DIR = libft
LIBFT = ./libft.a

LIB = $(LIBFT)
FLAGS = -Wall -Werror -Wextra

NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

BOLD=\033[1m

all : $(NAME)

lib : $(LIBFT)

$(LIBFT) :
	echo "Loading libft";\
	make -C $(LIBFT_DIR);\
	mv $(LIBFT_DIR)/libft.a $(LIBFT_FILE);\

$(OBJ) :
	

$(OBJ_BONUS) :


gen_bricks :
	@gcc $(FLAGS) $(SRCS) -c

$(NAME) : gen_bricks lib
	@gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIB)
	@echo "$(GREEN)pipex ready to be executed.$(NC)"

debug : libft.a
	@gcc $(FLAGS) -g3 $(SRCS) -o $(NAME) $(LIB)
	@echo "$(GREEN)pipex ready to be executed.$(NC)"

clean :
	make -C $(LIBFT_DIR) clean
	/bin/rm -rf $(OBJS)
	/bin/rm -rf $(OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(NAME_BONUS)
	@/bin/rm -rf $(LIBFT)

re : fclean $(NAME)

bonus : lib
	@gcc $(FLAGS) $(SRCS_BONUS) -o $(NAME_BONUS) $(LIB)
	@echo "$(GREEN)pipex_bonus ready to be executed.$(NC)"

test : re
	./pipex a a a a