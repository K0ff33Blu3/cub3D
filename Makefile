# Nome degli eseguibili
NAME		:= cub3D

# Directories
SRC_DIR 	:= src
OBJ_DIR		:= obj
INC_DIR		:= include

# MiniLibX
MLX_DIR     := $(INC_DIR)/minilibx-linux
MLX_FLAGS		:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

# Libreria
LIBFT_DIR	:= $(INC_DIR)/libft
LIBFT_LIB	:= $(LIBFT_DIR)/libft.a
LDFLAGS  	+= -L$(LIBFT_DIR) -lft

# Compilatore e flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g  -I$(INC_DIR) -I$(LIBFT_DIR)

# Sorgenti
SRCS		:= $(shell find $(SRC_DIR) -name "*.c")

# Oggetti (con prefisso obj/)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regola di default
all: $(NAME)

# --- 1) Creazione dell’executable base ---
# Assicuriamoci che obj/ esista, poi linkiamo
$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLX_FLAGS) -o $@
	@echo -e "\033[32m✔ $(NAME) created!\033[0m"

# --- 3) Rule per creare la cartella obj/
$(OBJ_DIR):
	@mkdir -p $@

# --- 4) Regola pattern per compilare ogni .c in obj/*.o
#     $< = file .c di input, $@ = obj/foo.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[90m• $< compiled\033[0m"

# --- 5) Compilazione della libft ---
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

# --- 6) Pulizia oggetti ---
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo -e "\033[33m✘ Objects removed.\033[0m"

# --- 7) Pulizia completa (oggetti + binari) ---
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo -e "\033[31m✘ Binaries wiped\033[0m"

# --- 8) Rebuild ---
re: fclean all

.PHONY: all clean fclean re