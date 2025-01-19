# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 01:24:15 by vnicoles          #+#    #+#              #
#    Updated: 2025/01/04 03:19:16 by vnicoles         ###   ########.fr        #
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
NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)
LIBS		= $(MLX_LIB) $(LIBFT_LIB) -lXext -lX11 -lm

# --- Paths ---
MLX_URL		= https://cdn.intra.42.fr/document/document/26198/minilibx-linux.tgz
MLX_DIR		= lib/minilibx
MLX_TGZ		= lib/mlx.tgz
MLX_LIB		= lib/libmlx.a
MLX			= libmlx.a
LIB_DIR		= lib
LIBFT_DIR	= lib/libft
LIBFT_LIB	= lib/libft.a
LIBFT 		= libft.a
INC_DIR		= inc/
SRC_DIR		= src/
SRC			= fdf.c \
				alg_utils.c \
				draw.c \
				input.c \
				line_alg.c \
				parse_map.c \
				projection.c \
				utils.c
OBJ_DIR		= obj/
OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
HEADERS		= $(INC_DIR)fdf.h

# --- Progress bar ---
TOTAL_FILES	= $(words $(SRC))
CURR_FILE	= 0
PERCENT		= $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc)

define update_progress
	@$(eval CURR_FILE = $(shell echo "$(CURR_FILE) + 1" | bc))
	@$(eval PERCENT = $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc))
	@printf "\r\033[K"
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)FDF$(RESET)]: \tCompiling... ["
	@printf "%*s" $(shell echo "$(PERCENT) * 20 / 100" | bc) "" | tr ' ' '='
	@printf "%*s" $(shell echo "20 - ($(PERCENT) * 20 / 100)" | bc) "" | tr ' ' '.'
	@printf "] %3d%% %s" $(PERCENT)
	@printf " %s" $(notdir $<)
endef

# --- Rules ---
all: $(LIBFT_LIB) $(MLX_LIB) $(OBJ_DIR) $(NAME)


$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@printf "\r\033[K$(RESET)$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)FDF$(RESET)]: \tCompiled  ["
	@printf "%*s" 20 "" | tr ' ' '='
	@printf "] "
	@printf "100%% "
	@printf "$(GREEN)Complete!$(RESET)\n"

$(MLX_LIB):
	@if [ ! -f $(MLX_LIB) ]; then \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)MLX$(RESET)]: \tDownloading...\n" && \
		curl -o $(MLX_TGZ) $(MLX_URL) 2>/dev/null && \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)MLX$(RESET)]: \tExtracting...\n" && \
		tar -xf $(MLX_TGZ) -C $(LIB_DIR) 2>/dev/null && \
		mv $(LIB_DIR)/minilibx-linux $(MLX_DIR) && \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)MLX$(RESET)]: \tBuilding...\n" && \
		make -C $(MLX_DIR) >/dev/null 2>&1 && \
		mv $(MLX_DIR)/libmlx.a $(LIB_DIR) && \
		mv $(MLX_DIR)/mlx.h $(INC_DIR) && \
		rm $(MLX_TGZ) && \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)MLX$(RESET)]: \tMLX $(GREEN)ready$(RESET)\n" && \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)FDF$(RESET)]: \tFlags: $(GREY)$(CC) $(CFLAGS)$(RESET)\n"; \
	else \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)MLX$(RESET)]: \tMLX $(GREEN)ready$(RESET)\n" && \
		printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)FDF$(RESET)]: \tFlags: $(GREY)$(CC) $(CFLAGS)$(RESET)\n"; \
	fi

$(LIBFT_LIB):
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)LIBFT$(RESET)]: \tBuilding..."
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/libft.a $(LIB_DIR)
	@cp $(LIBFT_DIR)/inc/libft.h $(INC_DIR)
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)LIBFT$(RESET)]: \tLIBFT $(GREEN)ready$(RESET)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call update_progress)


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(MLX_DIR)
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)MLX$(RESET)]: \tCleaned\n"

fclean: clean
	@rm $(NAME)
	@rm $(LIB_DIR)/libmlx.a
	@rm $(LIB_DIR)/libft.a
	@printf "$(GREEN)»$(RESET) [$(PURPLE)$(BOLD)FDF$(RESET)]: \t$(GREEN)Full clean$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
