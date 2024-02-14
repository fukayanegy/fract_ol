# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:33:21 by etakaham          #+#    #+#              #
#    Updated: 2024/02/14 14:26:48 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= fract_al
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SANITIZE	= -fsanitize=address -g
RE			= rm -f
MAIN		= src/main.c
SRCS		= src/ft_atof.c src/julia.c src/mandelbrot.c  src/complex_operations/comp_add.c src/complex_operations/comp_malt.c src/complex_operations/comp_square.c src/init_functions/init_color.c src/init_functions/init_complex.c src/init_functions/init_image.c src/init_functions/init_mlx_data.c src/utils/close_window_hook.c src/utils/esc_key_hook.c src/utils/ft_rgb.c src/utils/mouse_hook.c src/utils/my_mlx_pixel_put.c
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
