NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Diretorios
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
SRCS_DIR = src
OBJS_DIR = obj

# Bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Arquivos fonte
SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/window.c \
		$(SRCS_DIR)/parse.c \
		$(SRCS_DIR)/fdf.c \
#        $(SRCS_DIR)/events.c \
#        $(SRCS_DIR)/utils.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Cores para output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ FDF compilado com sucesso!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compilado: $<$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "$(GREEN)Compilando libft...$(RESET)"
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)✓ Libft compilada!$(RESET)"

$(MLX):
	@echo "$(GREEN)Compilando MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) --no-print-directory
	@echo "$(GREEN)✓ MiniLibX compilada!$(RESET)"

clean:
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)✗ Objetos removidos$(RESET)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME)
	@echo "$(RED)✗ Executável removido$(RESET)"

re: fclean all

.PHONY: all clean fclean re