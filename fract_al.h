#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"

# define HEIGHT 800
# define WIDTH 800

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
