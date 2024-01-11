# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 06:55:38 by codespace         #+#    #+#              #
#    Updated: 2024/01/11 19:58:59 by sinlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc
CFLAGS = -ggdb -fsanitize=address
INCLUDES = -Iincludes -Ilib/ft_printf/inc -Ilib/ft_printf/libft/includes -I/usr/include -Ilib/mlx_linux -O3

# Source files
SRCS_DIR = srcs
MAIN_DIR = main
DRAW_DIR = draw
# SRCS_FILES = $(addprefix $(MAIN_DIR)/, main.c) \ 
# 			 $(addprefix $(DRAW_DIR)/, xiaolin_wu.c) \

SRCS_FILES = $(addprefix $(MAIN_DIR)/, main.c controls.c) \
			 $(addprefix $(DRAW_DIR)/, xiaolin_wu.c utils.c) \

SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

# Object files
OBJS_DIR = objs
# OBJS_DIRS = $(OBJS_DIR) $(OBJS_DIR)/$(BUILTINS_DIR) $(OBJS_DIR)/$(EXEC_DIR) $(OBJS_DIR)/$(MAIN_DIR) $(OBJS_DIR)/$(PARSING_DIR) $(OBJS_DIR)/$(TOOLS_DIR)
OBJS_DIRS = $(OBJS_DIR) $(OBJS_DIR)/$(MAIN_DIR) $(OBJS_DIR)/$(DRAW_DIR)
OBJS_FILES = $(patsubst %.c,%.o,$(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJS_FILES))

# Libraries
PRINTF_DIR = lib/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = lib/mlx_linux
MLX = $(MLX_DIR)/libmlx.a


MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBS = -L$(PRINTF_DIR) -lftprintf -lreadline

# Binary
NAME = fdf

# Colors and text formatting
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m

# Makefile rules
all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(MLX)
	@echo "$(BOLD)$(LIGHT_BLUE)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)"
	@echo "$(BOLD)Copyright Reserved. Lee Sin Liang."

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIRS)
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	@echo "$(BOLD)$(LIGHT_BLUE)Building mlx...$(RESET)"
	@make -C $(MLX_DIR) -s

$(PRINTF):
	@echo "$(BOLD)$(LIGHT_BLUE)Building ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) -s

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@rm -f a.out
	@make -C $(PRINTF_DIR) clean -s

fclean: clean
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re
