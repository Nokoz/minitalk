NAME = minitalk

SERVER = server

CLIENT = client

SRC_SERV = server.c

SRC_CLIENT = client.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SERV) minitalk.h
	$(CC) $(FLAGS) -o $(SERVER) $(SRC_SERV)

$(CLIENT): $(SRC_CLIENT) minitalk.h
	$(CC) $(FLAGS) -o $(CLIENT) $(SRC_CLIENT)


clean:
	rm -rf $(CLIENT) $(SERVER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
