# include "fract_al.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	int		i, j;
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "fract-ol");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			// Red		0x00FF0000
			// Green	0x0000FF00
			// Blue		0x000000FF
			if (i <= 300)
				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			else if (i <= 600)
				my_mlx_pixel_put(&img, i, j, 0x0000FF00);
			else
				my_mlx_pixel_put(&img, i, j, 0x000000FF);
			j += 1;
		}
		i += 1;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
