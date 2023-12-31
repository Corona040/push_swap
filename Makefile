NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = libft.a

SRCS = push_swap.c		\
	   handle_args.c	\
	   init_stack.c

HDRS = push_swap.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
