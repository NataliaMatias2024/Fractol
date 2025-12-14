# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 19:25:38 by namatias          #+#    #+#              #
#    Updated: 2025/12/14 14:09:37 by namatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                            Variaveis / Variables                             #
################################################################################

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_SRC = src/Libft/ft_atoi.c \
			src/Libft/ft_itoa.c \
			src/Libft/ft_atol.c \
			src/Libft/ft_bzero.c \
			src/Libft/ft_split.c \
			src/Libft/ft_memcpy.c \
			src/Libft/ft_memset.c \
			src/Libft/ft_strdup.c \
			src/Libft/ft_calloc.c \
			src/Libft/ft_strchr.c \
			src/Libft/ft_strlen.c \
			src/Libft/ft_memchr.c \
			src/Libft/ft_memcmp.c \
			src/Libft/ft_substr.c \
			src/Libft/ft_putnbr.c \
			src/Libft/ft_isalpha.c \
	   		src/Libft/ft_isdigit.c \
			src/Libft/ft_isalnum.c \
			src/Libft/ft_isascii.c \
			src/Libft/ft_isprint.c \
			src/Libft/ft_toupper.c \
			src/Libft/ft_tolower.c \
			src/Libft/ft_strlcpy.c \
			src/Libft/ft_strlcat.c \
			src/Libft/ft_strnstr.c \
			src/Libft/ft_strrchr.c \
			src/Libft/ft_strncmp.c \
			src/Libft/ft_memmove.c \
			src/Libft/ft_strtrim.c \
			src/Libft/ft_strmapi.c \
			src/Libft/ft_strjoin.c \
			src/Libft/ft_striteri.c \
			src/Libft/ft_putstr_fd.c \
			src/Libft/ft_putnbr_fd.c \
			src/Libft/ft_putendl_fd.c \
			src/Libft/ft_putchar_fd.c \
			src/Libft/ft_str_is_numeric.c \


PRINTF_SRC = src/ft_printf/ft_put_c.c \
			 src/ft_printf/ft_put_p.c \
			 src/ft_printf/ft_put_s.c \
			 src/ft_printf/ft_put_x.c \
			 src/ft_printf/ft_printf.c \
			 src/ft_printf/ft_put_nbr.c \
			 src/ft_printf/ft_put_nbr_u.c \
			 src/ft_printf/ft_put_x_upper.c \

SRC_DIR =	./src/

FILESC = $(LIBFT_SRC) $(PRINTF_SRC)
FILESO = $(FILESC:.c=.o)

################################################################################
#                               Cores / Colors                                 #
################################################################################

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

################################################################################
#                             Funções / Functions                              #
################################################################################

all: $(NAME)
	
$(NAME): $(FILESO)
	@echo "$(YELLOW) Compiling Libft...$(RESET)"
	@ar rcs $(NAME) $(FILESO)
	@echo "$(GREEN) Libft compiled$(RESET)"

%.o : %.c
	@$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(FILESO)
	@echo "$(RED) Libft *.o files deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) Libft.a deleted$(RESET)"

re:
	@$(MAKE) fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
