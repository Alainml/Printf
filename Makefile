# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almirand <almirand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:25:42 by almirand          #+#    #+#              #
#    Updated: 2022/05/10 12:55:14 by almirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c	ft_printf_utils.c

SRC_BONUS = ft_printf_bonus.c	ft_printf_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

AR = ar -crs

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $@ $^

%.o:		%.c
			$(CC) $(FLAGS) $^

bonus:	$(OBJ_BONUS)
		$(AR) $(NAME) $^

clean:
			@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
