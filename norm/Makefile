# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 20:31:52 by salmanso          #+#    #+#              #
#    Updated: 2022/11/09 00:15:34 by salmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

SERSRC		= server.c

CLISRC		= client.c


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR	= \033[0;39m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
PINK		= \033[0;35m

#Sourcess

SER_OBJ		= 	$(SERSRC:.c=.o)
CLI_OBJ		= 	$(CLISRC:.c=.o)

###

all			: server client

server:
			${CC} $(SERSRC) -c
			${CC} ${CFLAGS} -o server $(SERSRC)
			@echo "$(GREEN)Server successfully compiled!$(DEF_COLOR)"

client:
			$(CC) $(CLISRC) -c
			$(CC) ${CFLAGS} -o client $(CLISRC)
			@echo "$(GREEN)Client successfully compiled!$(DEF_COLOR)"

clean:
			@$(RM) client server
			@echo "$(YELLOW)Client/Server object files successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(SER_OBJ)
			@$(RM) $(CLI_OBJ)
			@echo "$(CYAN)Client/Server executable files successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(PINK)Successfully cleaned and rebuilt everything for Minitalk!$(DEF_COLOR)"

norm:
			@norminette $(SERSRC) $(CLISRC) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
