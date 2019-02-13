# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 12:07:01 by kemethen          #+#    #+#              #
#    Updated: 2019/02/13 12:46:09 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_bzero.c \
	ft_strlen.c \
	ft_strnew.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_displaytab.c \
	ft_strncpy.c \
	ft_strndup.c 
	
OBJ = $(subst srcs/, ,$(SRC:.c=.o))

HEAD = libft.h

all:  $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
