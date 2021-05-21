
NAME = push_swap

LIBFT =	libft/

CHECKER =	bonus/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

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
		main.c

OBJ := ${SRC:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
$(NAME): $(OBJ)
	@ make -C $(LIBFT)
	@ cp $(LIBFT)libft.a .
	@ make -C $(CHECKER)
	@ cp $(CHECKER)checker .
	$(CC) $(CFLAGS) $(SRC) libft.a -o $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -f ${OBJ} libft.a
	rm -f $(LIBFT)libft.a
	make clean -C $(CHECKER)
fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(CHECKER)
	rm -f $(NAME)
	rm -f checker
re: fclean all