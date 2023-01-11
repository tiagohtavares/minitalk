# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:13:01 by ttavares          #+#    #+#              #
#    Updated: 2023/01/11 13:31:38 by ttavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSSERVER	= server.c
SRCSCLIENT	= client.c

OBJS	=	$(SRCS:.c=.o)

CC	= cc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME	=
SERVER = server
CLIENT = client

all:	$(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(SRCSSERVER) -o $(SERVER)

$(client):
	$(CC) $(SRCSCLIENT) -o $(client)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(SERVER) $(CLIENT)

re:	fclean $(SERVER) $(CLIENT)

bonus:

.PHONY:	all clean fclean re bonus
