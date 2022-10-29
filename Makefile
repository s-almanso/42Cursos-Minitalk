# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 11:02:17 by alialmar          #+#    #+#              #
#    Updated: 2022/10/29 15:17:41 by salmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERSRC	= server.c

CLISRC = client.c

SEROBJ		= $(SERSRC:.c=.o)
CLTOBJ		= $(CLISRC:.c=.o)

RM			= rm -f
CC			= gcc
// CFLAGS		= -Wall -Wextra -Werror

.c.o:	${CC} -c $< o ${<:.c=.o}

all : 		server client

server : $(SEROBJ)
			$(CC) $(CFLAGS) $(SEROBJ) -o server

client : $(CLTOBJ)
			$(CC) $(CFLAGS) $(CLTOBJ) -o client

clean :
		$(RM) $(SEROBJ) $(CLTOBJ)

fclean : clean
		$(RM) server client

re : 	fclean  all

.PHONY: all clean fclean re .c.o
