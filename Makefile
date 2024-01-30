# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:33:21 by etakaham          #+#    #+#              #
#    Updated: 2024/01/30 14:02:37 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= fract_al
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RE			= rm -f
MAIN		= src/main.c
SRCS		= src/mandelbrot.c src/julia.c src/ft_atof.c src/complex_operations.c src/utils.c
OBJS		= $(SRCS:.c=.o)
OBJ_DIR		= ./obj

MLX_DIR		= ./include/minilibx
MLX_FLAGS	= -L$(MLX_DIR)
MLX_COM		= -lm -L/usr/X11R6/lib -L minilibx -lmlx -lX11 -lXext -framework OpenGL -framework AppKit
MLX			= ./include/minilibx/libmlx.a

LIBFT_DIR	= ./include/libft
LIBFT		= ./include/libft/libft.a

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT) $(MLX_COM) $(MLX) $^ -o $@
	@echo "Compilation is complete."

clean:
	@make -C $(LIBFT_DIR) fclean
	@$(RE) $(OBJS)
	@echo "Deleted object files."

fclean:clean
	@$(RE) $(NAME)
	@echo "Deleted application."

re:fclean all
