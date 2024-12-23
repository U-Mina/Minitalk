# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 11:40:32 by ewu               #+#    #+#              #
#    Updated: 2024/11/04 14:31:55 by ewu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER) $(CLIENT)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -crs

SRC = server.c \
				client.c
SRC_BONUS = server_bonus.c \
				client_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


$(SERVER): server.o
	$(CC) $(CFLAGS) -o $@ $^
$(CLIENT): client.o
	$(CC) $(CFLAGS) -o $@ $^
$(BONUS_SERVER): server_bonus.o
	$(CC) $(CFLAGS) $< -o $@ 
$(BONUS_CLIENT): client_bonus.o
	$(CC) $(CFLAGS) $< -o $@ 

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	rm -rf $(OBJ)

fclean: clean
		rm -rf $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT) ${OBJ_BONUS}

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus