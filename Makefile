
CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = cd libft && make
LIB = libft/libft.a

SERVER = server.c
CLIENT = client.c

SERVER_SRC = $(SERVER)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

NAME = serv
SERV_NAME = server
CLIENT_NAME = client

CLIENT_SRC = $(CLIENT)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

all: $(NAME)

$(NAME): bibli server client

bibli: 
		@$(LIBFT)

server: $(SERVER_OBJ)
		@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB) -o $(SERV_NAME)

client: $(CLIENT_OBJ) bibli
		@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB) -o $(CLIENT_NAME)

clean: 
	$(RM) $(OBJS)
	 cd libft && make clean

fclean: 
		$(RM) $(CLIENT_NAME) $(SERV_NAME) $(OBJS)
		cd libft && make fclean

re: fclean all

.PHONY: all server client clean fclean re bibli
