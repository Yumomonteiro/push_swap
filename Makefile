NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

SRCS	= ./push_swap.c \
		  ./reverse_rotate.c \
		  ./rotate.c \
		  ./swap.c \
		  ./push.c \
		  ./utils.c \
		  ./small_algo.c \
		  ./sort_stack.c \

LIBFT	= libs/libft/libft.a
FT_PRINTF = libs/ft_printf/libftprintf.a
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C libs/libft

$(FT_PRINTF):
	make -C libs/ft_printf

clean:
	$(RM) $(OBJS)
	make clean -C libs/libft
	make clean -C libs/ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/libft
	make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re
