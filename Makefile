# Standard
NAME                = so_long

# Directories
LIBFT               = ./libft/libft.a
PRINTF              = ./ft_printf/libftprintf.a
INC                 = include/
SRC_DIR             = src/
OBJ_DIR             = obj/
GNL_DIR             = get_next_line/

# Compiler and CFlags
CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra  -g
RM                  = rm -f

# Additional flags
INCLUDES            = -I /usr/local/include
LIBRARIES           = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

# Source files
SRCS                = main.c  map_setup.c map_format.c
GNL_SRCS            = get_next_line.c get_next_line_utils.c

# File paths
SRC                 = $(addprefix $(SRC_DIR), $(SRCS))
GNL_SRC             = $(addprefix $(GNL_DIR), $(GNL_SRCS))
OBJ                 = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) $(GNL_SRCS:.c=.o))

all:                $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft > /dev/null
	@echo "\033[1;32mLibft.a has been created.\033[0m"

$(PRINTF):
	@echo "Compiling printf..."
	@make -C ./ft_printf > /dev/null
	@echo "\033[1;32mPrintf.a has been created.\033[0m"

obj:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "\033[1;31mDirectory already created.\033[0m"; \
	else \
		mkdir -p $(OBJ_DIR); \
		echo "Directory obj/ with files .o is being created..."; \
	fi

$(NAME):       $(LIBFT) $(PRINTF) obj $(OBJ)
	@if [ -f $(NAME) ]; then \
		echo "\033[1;31mso_long still exists.\033[0m"; \
	else \
		echo "Compiling so_long..."; \
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME) $(LIBRARIES); \
		echo "\033[1;32mDone.\033[0m"; \
	fi

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mFile created.\033[0m";

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -I$(GNL_DIR) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mFile created.\033[0m";

clean:
	@echo "Removing obj/..."
	@$(RM) -r $(OBJ_DIR)
	@echo "Removing so_long/obj..."
	@make clean -C ./libft > /dev/null
	@make clean -C ./ft_printf > /dev/null
	@echo "\033[1;32mAll Done for clean.\033[0m"

fclean: clean
	@echo "Removing so_long..."
	@$(RM) $(NAME)
	@echo "Removing libft.a..."
	@$(RM) $(LIBFT)
	@echo "Removing printf.a..."
	@$(RM) $(PRINTF)
	@echo "\033[1;32mDone.\033[0m"

re: fclean all

.PHONY: all obj clean fclean re
