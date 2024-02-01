NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

SRCS = push_swap.c		\
	   init_args.c		\
	   init_stack.c		\
	   utils.c			\
	   utils_ops.c		\
	   utils_turk.c		\
	   easy_sort.c

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C libft printf

clean:
	@make -C libft clean

fclean: clean
	rm -rf $(LIBFT) $(NAME)

re: fclean all

.PHONY: all clean fclean re
