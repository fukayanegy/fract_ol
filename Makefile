# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 17:33:21 by etakaham          #+#    #+#              #
#    Updated: 2024/03/23 16:10:46 by etakaham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SANITIZE	= -fsanitize=address -g
RE			= rm -f
MAIN		= src/main.c
SRCS		= src/complex_operations/comp_add.c src/complex_operations/comp_malt.c src/complex_operations/comp_square.c\
			  src/init_functions/init_color.c src/init_functions/init_complex.c src/init_functions/init_image.c src/init_functions/init_mlx_data.c\
			  src/julia/drow_julia.c src/julia/plot_julia.c\
			  src/mandelbrot/drow_mandelbrot.c src/mandelbrot/plot_mandelbrot.c\
			  src/utils/ft_atof.c src/utils/close_window_hook.c src/utils/esc_key_hook.c src/utils/ft_rgb.c src/utils/mouse_hook.c src/utils/my_mlx_pixel_put.c src/utils/minimize_hook.c src/utils/error_output.c src/utils/ft_count.c
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
	@make -C $(MLX_DIR) clean
	@$(RE) $(OBJS)
	@echo "Deleted object files."

fclean:clean
	@$(RE) $(NAME)
	@echo "Deleted application."

re:fclean all
