# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/14 14:18:30 by namatias          #+#    #+#              #
#    Updated: 2025/12/14 14:25:29 by namatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                FLAGS TO COMPILE                              #
################################################################################

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR =	./src/
OBJ_DIR =	./obj/

FILES_C = main.c \
		  main_utils.c \
		  fractal.c \
		  math_utils.c \
		  render.c

FILES_O = $(FILES_C:.c=.o)

OBJ = $(addprefix $(OBJ_DIR), $(FILES_O))
################################################################################
#                                    LIBRRIES                                  #
################################################################################

LIB_DIR =	./Libs/
LIBFT = $(LIB_DIR)libft.a
IFLAGS = -I$(LIB_DIR)include
LDFLAGS = -L $(LIB_DIR) -lft

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_INCLUDES = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I. $(LIBFT_INCLUDES) $(MLX_INCLUDES)
################################################################################
#                                   Colors                                     #
################################################################################

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

################################################################################
#                             Funções / Functions                              #
################################################################################

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(YELLOW) Compiling fractol...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN) Fractol compiled$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -f $(OBJ_DIR)*.o
	@make clean -C $(LIB_DIR) --silent
	@make clean -C $(MLX_DIR) --silent
	@echo "$(RED) Fractol *.o files deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR) --silent
	@echo "$(RED) Fractol executable deleted$(RESET)"

re:
	@$(MAKE) fclean 
	@$(MAKE) all

.PHONY: all clean fclean re