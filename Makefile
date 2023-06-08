# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:28:42 by ggiboury          #+#    #+#              #
#    Updated: 2023/06/08 21:04:40 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

NAME = pipex
NAME_BONUS = pipex_bonus

SRCS = 	ft_cmd_utils.c			\
		ft_exec.c				\
		ft_free.c				\
		ft_parse.c				\
		ft_utils.c				\
		pipes.c

S_MAIN = pipex.c

S_MAIN_BONUS = pipex_bonus.c


OBJS_COMMON = $(SRCS:.c=.o)

OBJ_MAIN = $(S_MAIN:.c=.o)
OBJ_MAIN_BONUS = $(S_MAIN_BONUS:.c=.o)


LIBFT_DIR = libft
LIBFT = ./libft.a

LIB = $(LIBFT)
FLAGS = -Wall -Werror -Wextra
CC = gcc

NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

BOLD=\033[1m

all : $(NAME)

lib : $(LIBFT)

$(LIBFT) :
	@echo "Loading libft"
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/libft.a $(LIBFT)

$(OBJS_COMMON) : $(SRCS)
	@gcc $(FLAGS) $? -c

$(OBJ_MAIN) : $(S_MAIN)
	@gcc $(FLAGS) $? -c
	
$(OBJ_MAIN_BONUS) : $(S_MAIN_BONUS)
	@gcc $(FLAGS) $? -c

$(NAME) : $(OBJS_COMMON) $(OBJ_MAIN) lib
	@gcc $(FLAGS) $(OBJS_COMMON) $(OBJ_MAIN) -o $(NAME) $(LIB)
	@echo "$(GREEN)pipex ready to be executed.$(NC)"

debug : $(OBJS_COMMON) $(OBJ_MAIN) lib
	@gcc $(FLAGS) $(OBJS_COMMON) $(OBJ_MAIN) -o $(NAME) $(LIB)
	@valgrind --leak-check=full ./pipex a a a a
	
clean :
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJS_COMMON)
	@/bin/rm -rf $(OBJ_MAIN)
	@/bin/rm -rf $(OBJ_MAIN_BONUS)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(NAME_BONUS)
	@/bin/rm -rf $(LIBFT)

re : fclean $(NAME)

bonus : $(OBJS_COMMON) $(OBJ_MAIN_BONUS) lib
	@gcc $(FLAGS) $(OBJS_COMMON) $(OBJ_MAIN_BONUS) -o $(NAME_BONUS) $(LIB)
	@echo "$(GREEN)pipex_bonus ready to be executed.$(NC)"
