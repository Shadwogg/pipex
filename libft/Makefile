# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:40:45 by ggiboury          #+#    #+#              #
#    Updated: 2023/01/31 22:26:54 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c 		\
	  ft_isdigit.c 		\
	  ft_isalnum.c		\
	  ft_isascii.c		\
	  ft_isprint.c		\
	  ft_strlen.c		\
	  ft_memset.c		\
	  ft_bzero.c		\
	  ft_memcpy.c		\
	  ft_memmove.c		\
	  ft_strlcpy.c		\
	  ft_strlcat.c		\
	  ft_toupper.c		\
	  ft_tolower.c		\
	  ft_strchr.c		\
	  ft_strrchr.c		\
	  ft_strncmp.c		\
	  ft_memchr.c		\
	  ft_memcmp.c		\
	  ft_strnstr.c		\
	  ft_atoi.c			\
	  ft_calloc.c		\
	  ft_strdup.c		\
	  ft_substr.c		\
	  ft_strjoin.c		\
	  ft_strtrim.c		\
	  ft_split.c		\
	  ft_itoa.c			\
	  ft_strmapi.c		\
	  ft_striteri.c		\
	  ft_putchar_fd.c	\
	  ft_putstr_fd.c	\
	  ft_putendl_fd.c	\
	  ft_putnbr_fd.c	

SRC_BONUS = ft_lstnew_bonus.c		\
			ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c		\
			ft_lstlast_bonus.c		\
			ft_lstadd_back_bonus.c	\
			ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		\
			ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c

SRC_PRINTF = ft_printf.c	\
		ft_printf_arg.c		\
		ft_print_nbr.c		\
		ft_print_pointer.c	

SRC_GNL = get_next_line_bonus.c		\
		get_next_line_utils_bonus.c		

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)

ALL_SRC = $(SRC) $(SRC_BONUS) $(SRC_PRINTF) $(SRC_GNL)
ALL_OBJ = $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra $(ALL_SRC) -c
	@ar rc $(NAME) $(ALL_OBJ)

clean:
	@/bin/rm -f $(ALL_OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re: fclean all

#bonus : $(NAME)
#	@gcc -Wall -Werror -Wextra $(SRC_BONUS) -c
#	@ar rc $(NAME) $(OBJ_BONUS)
