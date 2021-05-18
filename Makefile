
NAME = push_swap

LIBFT =	libft/

#GNL =	get_next_line/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	push_swap00.c \
		push_swap01.c \
		push_swap02.c \
		push_swap03.c \
		utilities0.c \
		utilities1.c \
		utilities2.c \
		utilities3.c \
		operation00.c \
		operation01.c \

#SRCG = 	$(wildcard $(GNL)*.c)

OBJ := ${SRC:.c=.o}

#OBJG := $(SRCG:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
$(NAME): $(OBJ)
	@ make -C $(LIBFT)
	@ cp $(LIBFT)libft.a .
	$(CC) $(CFLAGS) $(SRC) libft.a -o $(NAME)
	make clean

clean:
	make clean -C $(LIBFT)
	rm -f ${OBJ} libft.a

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME) 

re: fclean all