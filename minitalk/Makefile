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
#BONUS			= minitalk_b

SRC_DIR			= ./src/
SERVER_SRC		= ./src/server.c
CLIENT_SRC		= ./src/client.c

LIBFT			= lib/libft.a
LIBFT_DIR		= ./lib
OBJ_DIR			= ./obj/
SERVER_OBJ		= ${SERVER_SRC:.c=.o}
CLIENT_OBJ		= ${CLIENT_SRC:.c=.o}
#SERVER_OBJS		= ${addprefix ${OBJ_DIR}, ${SERVER_SRCS:.c=.o}}
#CLIENT_OBJS		= ${addprefix ${OBJ_DIR}, ${CLIENT_SRCS:.c=.o}}

CC				= cc
CCFLAGS			= -Wall -Wextra -Werror -I./inc
RM				= rm -rf

# ${OBJ_DIR}%.o:	${SRC_DIR}%.c
# 			@printf "${CLEAR}${RESET}${GREEN}>>${RESET} [${PURPLE}${BOLD}Minitalk${RESET}]: Compiling ${GREEN}%s${RESET}...${GREY}" ${notdir $<}
# 			@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all:			${SERVER} ${CLIENT}


${SERVER} ${CLIENT}:		${LIBFT} ${SERVER_OBJ} ${CLIENT_OBJ}
						@${CC} ${CCFLAGS} ${SERVER_OBJ} ${LIBFT} -o ${SERVER}
						@${CC} ${CCFLAGS} ${CLIENT_OBJ} ${LIBFT} -o ${CLIENT}

${LIBFT}:
			@${MAKE} -C ${LIBFT_DIR}

clean:
			@${MAKE} clean -C ${LIBFT_DIR}
			@${RM} ${OBJ_DIR}
			@printf "${CLEAR}${RESET}${GREEN}>>${RESET} [${PURPLE}${BOLD}Minitalk${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"

fclean:			clean
			@${MAKE} fclean -C ${LIBFT_DIR}
			@${RM} ${SERVER} ${CLIENT}
			@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}Minitalk${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

re:				fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re