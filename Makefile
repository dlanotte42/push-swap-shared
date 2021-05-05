# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fd-agnes <fd-agnes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 17:51:37 by fd-agnes          #+#    #+#              #
#    Updated: 2021/05/05 18:06:29 by fd-agnes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

SRCS =	checker.c \
		./minilibft/ft_split.c \
		./minilibft/ft_itoa.c \


OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME2):	$(OBJS2)
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

clean: 		$(MAKE) clean
			$(RM) $(OBJS) $(OBJS2)

fclean:
			$(RM) $(OBJS) $(OBJS2) $(NAME) $(NAME2)

re: 		fclean $(NAME) $(NAME2)

.PHONY: 	all clean fclean re

