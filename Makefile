# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:13:01 by ttavares          #+#    #+#              #
#    Updated: 2023/01/19 13:07:15 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSSERVER	= server.c
SRCSCLIENT	= client.c

SRCSSERVERBONUS	= server_bonus.c
SRCSCLIENTBONUS	= client_bonus.c

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SERVER = server
CLIENT = client

SERVERBONUS = server_bonus
CLIENTBONUS = client_bonus

all:	$(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): $(LIBFT)
	$(CC) $(SRCSSERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT)
	$(CC) $(SRCSCLIENT) $(LIBFT) -o $(CLIENT)

$(CLIENTBONUS): $(LIBFT)
	$(CC) $(SRCSCLIENTBONUS) $(LIBFT) -o $(CLIENTBONUS)

$(SERVERBONUS): $(LIBFT)
	$(CC) $(SRCSSERVERBONUS) $(LIBFT) -o $(SERVERBONUS)

bonus: $(SERVER) $(CLIENT) $(SERVERBONUS) $(CLIENTBONUS)


clean:
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(SERVER) $(CLIENT) $(SERVERBONUS) $(CLIENTBONUS)
	make fclean -C $(LIBFT_DIR)

re:	fclean $(SERVER) $(CLIENT)

.PHONY:	all clean fclean re bonus
