# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 12:28:00 by fballest          #+#    #+#              #
#    Updated: 2021/01/11 12:08:19 by jcsantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIB_DIR     =   libft/
OBJ_DIR     =   obj/
SRC_DIR     =   sources/
SRC_FILES = ft_printf.c \
			ft_printf_utils.c \
			fn_printf_print.c \
			fn_printf_struct.c \
			fn_printf_check.c \
			fn_printi_d.c \
			fn_print_c.c \
			fn_print_s.c \
			fn_printf_chk_str.c
SRC = $(SRC_FILES:%=$(SRC_DIR)%)
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LFLAGS = -I includes/
FLAGS = -g #-Wall -Wextra -Werror -g
CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

all:    $(OBJ_DIR) $(NAME)
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory
$(NAME):    $(OBJ)
			@echo Loading libft
			@make -C $(LIB_DIR)
			@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo =====DONE=====
$(OBJ): $(SRC)
		@$(MAKE) $(OBJ_FILES)
$(OBJ_FILES):
		@$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

test: re
	@$(CC) $(FLAGS) -c sources/main.c -o obj/main.o
	@$(CC) $(FLAGS) -o ft_printf.out $(NAME) obj/main.o
clean:
		@$(RM) $(OBJ_DIR)
		@$(RM) $(OBJS)
		@make -C $(LIB_DIR) clean
fclean: clean
		@$(RM) $(NAME)
		@$(RM) ft_printf.out
		@make -C $(LIB_DIR) fclean
re: fclean all
.PHONY: all clean fclean re
