NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = utils.c\
parse_flags.c\
parse.c\
main.c



OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

%.o: %.c push_swap.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re