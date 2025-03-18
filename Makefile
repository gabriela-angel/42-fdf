# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 19:22:50 by gangel-a          #+#    #+#              #
#    Updated: 2025/03/17 19:22:50 by gangel-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = fdf

# LIBS
LIBFT = libft.a
LIBFT_DIR = lib/libft/
MLX = libmlx42.a
MLX_PATH = lib/MLX42/
MLX_BUILD_PATH = $(MLX_PATH)/build

# COMPILATION AND FLAGS
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -Iinclude
LIB_PATHS = -L$(LIBFT_DIR) -L$(MLX_BUILD_PATH) -lmlx42 -lglfw -ldl -lm -lft -no-pie

# PATHS
SRC_DIR = src/
OBJ_DIR = obj/

# MANDATORY FILES AND OBJECTS
SRC = \
	color_utils.c \
	color.c \
	draw.c \
	error.c \
	fdf.c \
	ft_malloc.c \
	init.c \
	line.c \
	map.c \
	utils.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

# ------------------------------ Colors ------------------------------

GREEN_BOLD	=	\033[1;92m
YELLOW_BOLD	=	\033[1;93m
YELLOW		=	\033[0;33m
RED			=	\033[0;91m
MAGENTA 	=	\033[1;35m
CYAN		=	\033[0;96m
RESET		= \033[0m

# ------------------------------ Rules ------------------------------

all: $(MLX) $(LIBFT) $(OBJ_DIR) $(NAME)

$(MLX):
	@cmake $(MLX_PATH) -B $(MLX_BUILD_PATH)
	@make -C $(MLX_BUILD_PATH) -j4 --no-print-directory
	@printf "$(GREEN_BOLD)MLX42 built.$(RESET)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR) gnl --no-print-directory
	@printf "$(GREEN_BOLD)Libft with GNL compiled.$(RESET)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@printf "$(YELLOW)$@: $(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN_BOLD)Object compiled.$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $@$(MOVE_DIR)

$(NAME):  $(OBJ)
	@printf "$(GREEN_BOLD) => 100%%$(RESET)\n"
	@printf "$(YELLOW_BOLD)[fdf]:\t$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIB_PATHS) -o $@
	@printf "$(GREEN_BOLD) => Success!$(RESET)\n"

norm:
	@echo "\n$(CYAN)======= LIBFT =======$(RESET)"
	@norminette lib/libft | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(YELLOW)======= MANDATORY =======$(RESET)"
	@norminette src | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(CYAN)======= INCLUDES =======$(RESET)"
	@norminette include | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'

leak: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --suppressions=suppression_file.supp ./$(NAME) maps/test_maps/42.fdf

clean:
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_BUILD_PATH)
	@printf "$(CYAN)[fdf]:\tobject files$(RESET)$(GREEN_BOLD)  => Cleaned!$(RESET)\n"

fclean: clean
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME)
	@printf "$(CYAN)[LIBFT]:\texec. files$(RESET)$(GREEN_BOLD) => Cleaned!$(RESET)\n"
	@printf "$(CYAN)[fdf]:\texec. files$(RESET)$(GREEN_BOLD)  => Cleaned!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re leak