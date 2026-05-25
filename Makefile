CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = codexion

SRCS = coders/main.c coders/parsing.c \
		coders/parsing_utils.c \
		coders/time.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o codexion

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re