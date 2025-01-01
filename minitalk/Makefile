# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 11:10:11 by vnicoles          #+#    #+#              #
#    Updated: 2024/12/27 22:06:33 by vnicoles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Colors constants
PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m
CLEAR			= \r\033[K

# Executable
CLIENT			= client
SERVER			= server

SRC_DIR			= ./src/
SERVER_SRC		= server.c
CLIENT_SRC		= client.c

LIBFT			= lib/libft.a
LIBFT_DIR		= ./lib
OBJ_DIR			= ./obj/
INC_DIR			= ./inc/
SERVER_OBJ		= $(addprefix $(OBJ_DIR), $(SERVER_SRC:.c=.o))
CLIENT_OBJ		= $(addprefix $(OBJ_DIR), $(CLIENT_SRC:.c=.o))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I $(INC_DIR)
RM				= rm -rf

# Calculate total number of files and create variables for the progress bar
TOTAL_FILES	= $(words $(SERVER_SRC) $(CLIENT_SRC))
CURR_FILE	= 0
PERCENT		= $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc)

# Define the progress bar function (20 chars width)
define update_progress
		@$(eval CURR_FILE = $(shell echo "$(CURR_FILE) + 1" | bc))
		@$(eval PERCENT = $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc))
		@printf "\r\\033[K"
		@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)Minitalk$(RESET)]: \tCompiling... ["
		@printf "%*s" $(shell echo "$(PERCENT) * 20 / 100" | bc) "" | tr ' ' '='
		@printf "%*s" $(shell echo "20 - ($(PERCENT) * 20 / 100)" | bc) "" | tr ' ' '.'
		@printf "] %3d%% %s" $(PERCENT)
		@printf " %s" $(notdir $<)
endef

all:			$(OBJ_DIR) $(SERVER) $(CLIENT)
		@printf "\r\\033[K$(CLEAR)$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)Minitalk$(RESET)]: \tCompiled  ["
		@printf "%*s" 20 "" | tr ' ' '='
		@printf "] "
		@printf "100%% "
		@printf "$(GREEN)Complete!$(RESET)"
		@printf "\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			@$(CC) $(CFLAGS) -c $< -o $@
			$(call update_progress)

$(SERVER):		$(LIBFT) $(SERVER_OBJ)
			@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT):		$(CLIENT_OBJ)
			@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

$(LIBFT):
			@$(MAKE) -C $(LIBFT_DIR)

clean:
			@$(MAKE) clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_DIR)
			@printf "$(CLEAR)$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)Minitalk$(RESET)]: \tRemoved $(BOLD)OBJ$(BOLD)\n"

fclean:
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_DIR)
			@printf "$(CLEAR)$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)Minitalk$(RESET)]: \tRemoved $(BOLD)OBJ$(BOLD)\n"
			@$(RM) $(SERVER) $(CLIENT)
			@printf "$(CLEAR)$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)Minitalk$(RESET)]: \tRemoved $(BOLD)server.a$(RESET) and $(BOLD)client.a$(RESET)\n"
			#@printf "$(CLEAR)$(RESET)$(GREY)────────────────────────────────────────────────────────────────────────────\n"
			@printf "$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)Minitalk$(RESET)]: \tProject cleaned $(GREEN)successfully$(RESET)\n"
			#@printf "$(GREY)\n$(RESET)$(GREY)────────────────────────────────────────────────────────────────────────────\n$(RESET)"

re:				fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re
