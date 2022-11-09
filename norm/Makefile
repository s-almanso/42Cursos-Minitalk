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

SERVER		= server
SERSRC		= server.c
SER_OBJ		= $(SERSRC:.c=.o)

CLIENT		= client
CLISRC		= client.c
CLI_OBJ		= $(CLISRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

DEF_COLOR	= \033[0;39m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
PINK		= \033[0;35m

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(SER_OBJ)
			$(CC) $(CFLAGS) $(SERSRC) -o $(SERVER)
			@echo "$(GREEN)Server successfully compiled!$(DEF_COLOR)"

$(CLIENT):	$(CLI_OBJ)	
			$(CC) $(CFLAGS) $(CLISRC) -o $(CLIENT)
			@echo "$(GREEN)Client successfully compiled!$(DEF_COLOR)"

clean:
			@$(RM) $(CLIENT) $(SERVER)
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
