# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 13:20:26 by brandebr          #+#    #+#              #
#    Updated: 2023/12/13 17:51:00 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c parse_it.c ft_read_map.c get_next_line.c flood_map.c 

OBJ = $(SRC:%.c=%.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -g -I. -I./libft -I./ft_printf

LIBFT = ./Libft/libft.a
LIBFT_DIR = ./libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_DIR = ./ft_printf

MLX = ./mlx/libmlx.a
MLX_DIR = ./mlx

all: $(NAME) Makefile

%.o: %.c so_long.h ./Libft/libft.h ./ft_printf/libftprintf.h ./get_next_line/get_next_line.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)

$(FT_PRINTF):
	@make all -C $(FT_PRINTF_DIR)

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(MLX):
	@make all -C $(MLX_DIR)

fclean: clean
	/bin/rm -f $(OBJ) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)

re: fclean all 

.PHONY: all clean fclean re
