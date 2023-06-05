# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:28:42 by ggiboury          #+#    #+#              #
#    Updated: 2023/06/05 17:28:45 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c					\
		ft_cmd_utils.c			\
		ft_exec.c				\
		ft_free.c				\
		ft_parse.c				\
		ft_utils.c			

LIBFT_DIR = libft
LIBFT_FILE = ./libft.a

LIB = $(LIBFT_FILE)
FLAGS = -Wall -Werror -Wextra

NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

BOLD=\033[1m

all : $(NAME)

lib :
	@if [ ! -f $(LIBFT_FILE) ]; then \
		echo "Loading libft";\
		make -C $(LIBFT_DIR);\
		mv $(LIBFT_DIR)/libft.a $(LIBFT_FILE);\
	else \
		echo "$(GREEN)Lib $(BOLD)libft$(GREEN) already there.$(NC)";\
	fi

$(NAME) : lib
	@gcc -Wall -Werror -Wextra $(SRC) -o $(NAME) $(LIB)
	@echo "$(GREEN)pipex ready to be executed.$(NC)"

clean :
	make -C $(LIBFT_DIR) clean

fclean : clean
	make -C $(LIBFT_DIR) fclean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIBFT_FILE)

re : fclean $(NAME)
