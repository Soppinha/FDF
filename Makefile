# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 22:36:46 by svaladar          #+#    #+#              #
#    Updated: 2026/01/08 23:13:59 by svaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
CYAN		= \033[0;36m
MAGENTA		= \033[0;35m
RESET		= \033[0m

NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

VALGRIND	= valgrind
VG_FLAGS	= --leak-check=full --show-leak-kinds=all --track-origins=yes \
			  --verbose --log-file=valgrind.log
VG_TEST_MAP	= test_maps/42.fdf

LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux
INC_DIR		= include
SRC_DIR		= src
SRC_OBJ		= obj
HEADER		= include/fdf.h include/colors.h keys/fdf.h

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a
LIBS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/init.c \
			  $(SRC_DIR)/init_fdf.c \
			  $(SRC_DIR)/close.c \
			  $(SRC_DIR)/error.c \
			  $(SRC_DIR)/render.c \
			  $(SRC_DIR)/draw.c \
			  $(SRC_DIR)/color.c \
			  $(SRC_DIR)/map.c \
			  $(SRC_DIR)/map_utils.c \
			  $(SRC_DIR)/fill_point.c \
			  $(SRC_DIR)/read.c \
			  $(SRC_DIR)/read_utils.c \
			  $(SRC_DIR)/event.c \
			  $(SRC_DIR)/key_handle.c \
			  $(SRC_DIR)/menu.c \
			  $(SRC_DIR)/project.c \
			  $(SRC_DIR)/rotate.c \
			  $(SRC_DIR)/transform.c \
			  $(SRC_DIR)/utils.c
			  
OBJS 		= $(SRCS:$(SRC_DIR)/%.c=$(SRC_OBJ)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(CYAN)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

$(SRC_OBJ):
	@mkdir -p $(SRC_OBJ)

$(SRC_OBJ)/%.o: $(SRC_DIR)/%.c | $(SRC_OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(CYAN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "$(CYAN)Building minilibx...$(RESET)"
	@make -C $(MLX_DIR)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@rm -rf $(SRC_OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "$(GREEN)✓ Cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME) and logs...$(RESET)"
	@$(RM) $(NAME) valgrind.log
	@rm -rf $(SRC_OBJ)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✓ Full clean complete!$(RESET)"

re: fclean all

norm:
	@echo "$(CYAN)=======================================$(RESET)"
	@echo "$(CYAN)        Running Norminette...$(RESET)"
	@echo "$(CYAN)=======================================$(RESET)"
	@norminette $(SRC_DIR)/*.c $(INC_DIR) $(LIBFT_DIR) | grep -v "OK!" || true
	@echo "$(CYAN)=======================================$(RESET)"
	@if norminette *.c $(INC_DIR) $(LIBFT_DIR) | grep -q "Error"; then \
		echo "$(RED)✗ Norminette found errors!$(RESET)"; \
	else \
		echo "$(GREEN)✓ All files OK!$(RESET)"; \
	fi
	@echo "$(CYAN)=======================================$(RESET)"

leaks: $(NAME)
	@echo "$(MAGENTA)=======================================$(RESET)"
	@echo "$(MAGENTA)        Running Valgrind...$(RESET)"
	@echo "$(MAGENTA)=======================================$(RESET)"
	@echo "$(YELLOW)Test: $(VG_TEST_MAP)$(RESET)"
	@echo "$(YELLOW)Log: valgrind.log$(RESET)"
	@echo "$(CYAN)Press ESC to close properly$(RESET)"
	@$(VALGRIND) $(VG_FLAGS) ./$(NAME) $(VG_TEST_MAP)
	@echo "$(MAGENTA)=======================================$(RESET)"
	@grep "LEAK SUMMARY" valgrind.log -A 5 || true
	@grep "ERROR SUMMARY" valgrind.log || true
	@echo "$(MAGENTA)=======================================$(RESET)"
	@if grep -q "definitely lost: 0 bytes" valgrind.log && \
	    grep -q "indirectly lost: 0 bytes" valgrind.log; then \
		echo "$(GREEN)✓ No memory leaks detected!$(RESET)"; \
	else \
		echo "$(RED)✗ Memory leaks found! Check valgrind.log$(RESET)"; \
	fi
	@echo "$(MAGENTA)=======================================$(RESET)"

check: norm valgrind
	@echo "$(GREEN)=======================================$(RESET)"
	@echo "$(GREEN)      All checks completed!$(RESET)"
	@echo "$(GREEN)=======================================$(RESET)"

# Test
test: $(NAME)
	@echo "$(CYAN)Running tests...$(RESET)"
	@echo "$(YELLOW)1. No arguments:$(RESET)"
	@./$(NAME) || true
	@echo ""
	@echo "$(YELLOW)2. Non-existent file:$(RESET)"
	@./$(NAME) nonexistent.fdf || true
	@echo ""
	@echo "$(YELLOW)3. Wrong extension:$(RESET)"
	@./$(NAME) test.txt || true

.PHONY: all clean fclean re norm leaks check test