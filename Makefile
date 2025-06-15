# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 19:21:41 by pleblond          #+#    #+#              #
#    Updated: 2025/06/16 00:45:59 by pleblond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

CFLAGS = -Wall -Wextra -Werror -Iinclude -g -fPIC
LDFLAGS = -Llib -lftprintf
CC = cc

SERVER_SRC = server.c \
				server_utils.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) -o $(SERVER_NAME) $(SERVER_OBJ) $(CFLAGS) $(LDFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) -f $(SERVER_OBJ)
	$(RM) -f $(CLIENT_OBJ)

fclean: clean
	$(RM) -f $(SERVER_NAME)
	$(RM) -f $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
