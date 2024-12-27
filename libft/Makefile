SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c
BSRCS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		get_next_line.c \
		ft_printf.c \
		ft_printf_utils_1.c \
		ft_printf_utils_2.c

SRC_DIR       = ./src/
INC_DIR       = ./inc/
OBJ_DIR       = ./obj/
OBJS	       = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BOBJS	       = $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

CC		= cc
RM		= rm -rf
CFLAGS        = -Wall -Wextra -Werror -I $(INC_DIR)
NAME		= libft.a

# Calculate total number of files and create variables for the progress bar
TOTAL_FILES := $(words $(SRCS) $(BSRCS))
CURR_FILE := 0
PERCENT = $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc)
COMPLETE_MSG = "\033[32mComplete!\033[0m"  # Green text

# Define the progress bar function (40 chars width)
define update_progress
        @$(eval CURR_FILE = $(shell echo "$(CURR_FILE) + 1" | bc))
        @$(eval PERCENT = $(shell echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc))
        @printf "\r\\033[K"
        @printf "Compiling: ["
        @printf "%*s" $(shell echo "$(PERCENT) * 40 / 100" | bc) "" | tr ' ' '='
        @printf "%*s" $(shell echo "40 - ($(PERCENT) * 40 / 100)" | bc) "" | tr ' ' '.'
        @printf "] %3d%% %s" $(PERCENT)
		@printf " %s" $(notdir $<)
endef

all:		$(OBJ_DIR) $(NAME)
		@printf "\r\033[KCompiling: ["
		@printf "%*s" 40 "" | tr ' ' '='
		@printf "] "
		@printf "100%% "
		@printf $(COMPLETE_MSG)
		@printf "\n"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		$(call update_progress)

$(NAME):	$(OBJS) $(BOBJS)
		@ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
		@$(RM) $(OBJ_DIR)
		@echo "Cleaned object files"

fclean:	clean
		@$(RM) $(NAME)
		@echo "Cleaned library"

re:		fclean all

.PHONY:	all clean fclean re
