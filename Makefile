# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:55:42 by artvan-d          #+#    #+#              #
#    Updated: 2022/09/08 11:38:29 by artvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

RM = rm -rf
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = \
						ft_printf.h \

SRCS = \
						ft_printf_hexa.c \
						ft_printf_assist.c \
						ft_printf_ptr.c \
						ft_printf_unsigned.c \
						ft_printf.c \

OBJS = $(SRCS:.c=.o)

INCS = $(addprefix -I, $(INC))

all : $(NAME)

$(NAME) : $(OBJS)
				ar rcs $@ $^

clean :
				$(RM) $(OBJS)

fclean : clean
				$(RM) $(NAME)

re : fclean all

.c.o: $(SRCS)
				$(CC) $(FLAGS) -c -o $@ $<
