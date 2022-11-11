# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 20:31:52 by salmanso          #+#    #+#              #
#    Updated: 2022/11/09 23:58:36 by salmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server
SERSRC		= server.c
SER_OBJ		= $(SERSRC:.c=.o)

CLIENT		= client
CLISRC		= client.c
CLI_OBJ		= $(CLISRC:.c=.o)

CLIENT_B	= client_bonus
CLI_B_SRC	= client_bonus.c
CLI_B_OBJ	= $(CLI_B_SRC:.c=.o)

SERVER_B	= server_bonus
SER_B_SRC	= server_bonus.c
SER_B_OBJ	= $(SER_B_SRC:.c=.o)

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
			@$(CC) $(CFLAGS) $(CLISRC) -o $(CLIENT)
			@echo "$(GREEN)Client successfully compiled!$(DEF_COLOR)"

bonus:		$(CLI_B_OBJ) $(SER_B_OBJ)
			@$(CC) $(CFLAGS) $(CLI_B_SRC) -o $(CLIENT_B)
			@$(CC) $(CFLAGS) $(SER_B_SRC) -o $(SERVER_B)
			@echo "$(BLUE)Successfully compiled client/server bonus!$(DEF_COLOR)"

clean:
			@$(RM) $(CLIENT) $(SERVER)
			@echo "$(YELLOW)Client/Server object files successfully cleaned!$(DEF_COLOR)"
			@$(RM) $(CLIENT_B) $(SERVER_B)
			@echo "$(BLUE)Client/Server bonus object files successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(SER_OBJ)
			@$(RM) $(CLI_OBJ)
			@echo "$(CYAN)Client/Server executable files successfully cleaned!$(DEF_COLOR)"
			@$(RM) $(SER_B_OBJ)
			@$(RM) $(CLI_B_OBJ)
			@echo "$(BLUE)Client/Server bonus executable files successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(PINK)Successfully cleaned and rebuilt everything for Minitalk!$(DEF_COLOR)"

norm:
			@norminette $(SERSRC) $(CLISRC) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
