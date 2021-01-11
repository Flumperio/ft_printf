# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 11:39:06 by juasanto          #+#    #+#              #
#    Updated: 2020/12/29 10:58:46 by juasanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Formato basico de MakeFile
#objetivo: dependencias
#		instrucciones

SRCS = ft_putchar.c ft_putnbr.c ft_putstring.c ft_strcpy.c \
		ft_memset.c ft_bzero.c ft_memccpy.c ft_memmove.c ft_memcpy.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_islower.c ft_isupper.c ft_isascii.c ft_isprint.c\
		ft_isblank.c ft_isspace.c ft_isxdigit.c ft_toupper.c ft_tolower.c ft_strlen.c \
		ft_strncmp.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strrchr.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_atoi.c ft_substr.c ft_strjoin.c \
		ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strmapi.c \
		ft_split.c ft_strtrim.c ft_strjoin_clean.c ft_strrev.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstiter.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -f

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
