# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 12:28:00 by jcsantos          #+#    #+#              #
#    Updated: 2021/01/12 17:06:36 by jcsantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIB_DIR		=	libft/
OBJ_DIR		=	obj/
SRC_DIR		=	sources/
SRC_FILES = ft_printf.c \
			ft_printf_utils.c \
			fn_printf_print.c \
			fn_printf_struct.c \
			fn_printf_check.c \
			fn_printi_d.c \
			fn_print_c.c \
			fn_print_s.c \
			fn_printf_chk_str.c \
			fn_printf_fill.c
SRC = $(SRC_FILES:%=$(SRC_DIR)%)
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LFLAGS = -I includes/
FLAGS = -g #-Wall -Wextra -Werror -g
CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib
NORM = ~/.norminette/norminette.rb

RESET = \033[0m
YELLOW = \033[33m
CYAN = \033[36m
GREEN = \033[32m
PINK = \033[35m
RED = \033[31m

all:	$(OBJ_DIR) $(NAME)
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory
$(NAME):	$(OBJ)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
		@$(AR) $(NAME) $(OBJ)
		@echo "=========== DONE ==========$(RESET)"
$(OBJ): $(SRC)
		@echo "$(GREEN)=========== Compilando $(NAME) ==========="
		@$(MAKE) $(OBJ_FILES)
		@echo "$(GREEN)=========== DONE ===========$(RESET)"
$(OBJ_FILES):

		@$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
		@echo "$(GREEN)Compilando $@...$(RESET)"

test: re
		@echo "$(YELLOW)=========== Compilando TEST ==========="
		@$(CC) $(FLAGS) -c sources/main.c -o obj/main.o
		@$(CC) $(FLAGS) -o ft_printf.out $(NAME) obj/main.o
		@echo "$(YELLOW)=========== DONE ===========$(RESET)"
clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIB_DIR) clean
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		$(RM) ft_printf.out
		make -C $(LIB_DIR) fclean
		@echo "$(RED)=========== DONE ===========$(RESET)"
re: fclean all
norm: all
		$(NORM) $(SRC);
.PHONY: all clean fclean re
