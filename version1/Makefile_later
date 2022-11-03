# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 20:31:52 by salmanso          #+#    #+#              #
#    Updated: 2022/10/24 21:51:29 by salmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

SERSRC		= server.c

CLISRC		= client.c


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR	= \033[0;39m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m

#Sourcess

SER_OBJ 		= 	$(SERSRC:.c=.o)
CLI_OBJ 		= 	$(CLISRC:.c=.o)

###

all:	:	server client

server:		$(SER_OBJ)
			@make -C $(SERSRC)
			@$(AR) $(SERSRC) $(SER)
			@echo "$(GREEN)Server successfully compiled!$(DEF_COLOR)"

client:		$(CLI_OBJ)
			@make -C $(CLISRC)
			@$(AR) $(CLISRC) $(CLI)
			@echo "$(GREEN)Client successfully compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(OBJ)
			@make clean -C $(SRC)
			@echo "$(BLUE)client/server object files successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(SRC)
			@$(RM) -f $(OBJ)
			@echo "$(CYAN)Client executable files successfully cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)Server executable files successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Successfully cleaned and rebuilt everything for Minitalk!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
