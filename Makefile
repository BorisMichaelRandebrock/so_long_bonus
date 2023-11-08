# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 13:20:26 by brandebr          #+#    #+#              #
#    Updated: 2023/11/08 13:42:23 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c

OBJ = $(SRC:%.c=%.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -g -I. -I./libft -I.ft_printf

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

FT_PRINTF = ./ft_printf/ft_printf.a
FT_PRINTF_DIR = ./ft_printf

all: $(NAME) Makefile
