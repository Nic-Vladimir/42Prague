# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = get_next_line.a
HEADER = get_next_line.h
BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = $(BSRCS:.c=.o)
BONUS = get_next_line_bonus.a
BHEADER = get_next_line_bonus.h

# Rule to make all
all: $(NAME)

bonus: $(NAME) $(BONUS)

# Rule to create the executable
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BONUS): $(BONUS_OBJ)
	ar rcs $(BONUS) $(BONUS_OBJ)

# Rule to compile .c files to .o files
%.o: %.c $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJS) $(BONUS_OBJ)

# Rule to clean object files and executable
fclean: clean
	rm -f $(NAME) $(BONUS)

# Rule to recompile the project from scratch
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
