NAME = server client

SRC_DIR = ./src/

SRCS = $(SRC_SERV) $(SRC_CLIENT)

SRC_SERV = server.c

SRC_CLIENT = client.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRC_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
