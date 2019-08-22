# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 14:06:12 by jormond-          #+#    #+#              #
#    Updated: 2019/08/22 16:13:28 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf.a

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

INC		=	ft_printf.h

LIB		=	./libft/libft.a

SRC		=	ft_printf.c \
			bonuses.c \
			parce_struct.c \
			sorter.c \
			spec_format.c \
			struct_init.c \
			width_converter.c \
			minus_width_format.c

OBJS	=	$(SRC:.c=.o)

all : $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
	make -C ./libft re

$(OBJS):
	$(CC) $(CFLAGS) -c $< $(INC) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all