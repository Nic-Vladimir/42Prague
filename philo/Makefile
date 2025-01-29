# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnicoles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 21:36:09 by vnicoles          #+#    #+#              #
#    Updated: 2025/01/29 00:04:15 by vnicoles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Silence make ---
MAKEFLAGS += --no-print-directory

# --- Colors ---
PURPLE	= \033[38;5;141m
GREEN	= \033[38;5;46m
RED		= \033[0;31m
GREY	= \033[38;5;240m
RESET	= \033[0m
BOLD	= \033[1m
CLEAR	= \r\033[Ks

# --- Vars ---
NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -I $(INC_DIR)

# --- Paths ---
INC_DIR		= inc
SRC_DIR		= src/
SRC			= main.c \
			utils.c

OBJ_DIR		= obj/
OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
HEADERS		= $(INC_DIR)/philo.h

# --- Progress bar ---
TOTAL_FILES	= $(words $(SRC))
CURR_FILE	= 0
PERCENT		= $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc)

define update_progress
	@$(eval CURR_FILE = $(shell echo "$(CURR_FILE) + 1" | bc))
	@$(eval PERCENT = $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc))
	@printf "\r\033[K"
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)PHILO$(RESET)]: \tCompiling... ["
	@printf "%*s" $(shell echo "$(PERCENT) * 20 / 100" | bc) "" | tr ' ' '='
	@printf "%*s" $(shell echo "20 - ($(PERCENT) * 20 / 100)" | bc) "" | tr ' ' '.'
	@printf "] %3d%% %s" $(PERCENT)
	@printf " %s" $(notdir $<)
endef

# --- Rules ---
all:  $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "\r\033[K$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)PHILO$(RESET)]: \tCompiled  ["
	@printf "%*s" 20 "" | tr ' ' '='
	@printf "] "
	@printf "100%% "
	@printf "$(GREEN)Complete!$(RESET)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call update_progress)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)PHILO$(RESET)]: \t$(GREEN)Full clean$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
