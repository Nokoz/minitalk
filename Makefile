NAME = minitalk

SERVER = server

SERVER_BONUS = server_bonus

CLIENT = client

CLIENT_BONUS = client_bonus

SRC_SERV = server.c minitalk_utils.c

SRC_SERV_BONUS = server_bonus.c minitalk_utils.c

SRC_CLIENT = client.c minitalk_utils.c

SRC_CLIENT_BONUS = client_bonus.c minitalk_utils.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SERV) minitalk.h
	$(CC) $(FLAGS) -o $(SERVER) $(SRC_SERV)

$(SERVER_BONUS): $(SRC_SERV_BONUS) minitalk.h
	$(CC) $(FLAGS) -o $(SERVER_BONUS) $(SRC_SERV_BONUS)

$(CLIENT): $(SRC_CLIENT) minitalk.h
	$(CC) $(FLAGS) -o $(CLIENT) $(SRC_CLIENT)

$(CLIENT_BONUS): $(SRC_CLIENT_BONUS) minitalk.h
	$(CC) $(FLAGS) -o $(CLIENT_BONUS) $(SRC_CLIENT_BONUS)

clean:
	rm -rf $(CLIENT) $(SERVER)
	rm -rf $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
