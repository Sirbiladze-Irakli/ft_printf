# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 14:06:12 by jormond-          #+#    #+#              #
#    Updated: 2019/08/29 12:22:40 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC = gcc
# FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(addprefix $(LIBFT_DIRECTORY), $(LIBFT))

HEADERS_LIST = ft_printf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = 	arg_form.c bonuses.c form_plus.c form_tools.c form_space.c \
				ft_printf.c arg_form2.c form_hex.c \
				modif_checker.c parse_struct.c prec_converter.c sorter.c \
				struct_init.c width_converter.c form_uint_prec.c form_hex2.c \
				tools.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@cp $(LIBFT) ./$(NAME)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"	

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all