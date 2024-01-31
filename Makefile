NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBS = libft.a

SRCS = push_swap.c		\
	   init_args.c		\
	   init_stack.c		\
	   utils.c			\
	   utils_ops.c		\
	   utils_turk.c		\
	   easy_sort.c

HDRS = push_swap.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
