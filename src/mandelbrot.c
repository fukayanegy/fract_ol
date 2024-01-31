/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:53 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/31 16:21:15 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

int	mandelbrot(int n, double *comp)
{
	int			i;
	t_complex	*c;
	t_complex	*z;

	c = malloc(sizeof(t_complex));
	z = malloc(sizeof(t_complex));

	c->r = comp[0];
	c->i = comp[1];
	z->r = 0;
	z->i = 0;

	i = 0;
	while (i < n)
	{
		z = comp_add(comp_malt(z, z), c);
		if (comp_abs(z) >= 2)
			return (i);
		i++;
	}
	return n;
}

void	drow_mandelbrot(t_data *img, double magnification_rate)
{
	int	repeat = 50;
	int	i, j, k;
	t_complex	c;
	(void)magnification_rate;

	i = 0;
	while (i < WIDTH)
	{
		c.r = ((double)i * 4 / WIDTH - 4 / 2) * magnification_rate;
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0x00000000);
			j += 1;
		}
		i += 1;
	}

	i = 0;
	while (i < WIDTH)
	{
		c.r = ((double)i * 4 / WIDTH - 4 / 2) * magnification_rate;
		j = 0;
		while (j < HEIGHT)
		{
			c.i = ((double)j * 4 / HEIGHT - 4 / 2) * magnification_rate;
			double a = 0.0, b = 0.0;
			double _a, _b;
			k = 0;
			while (k < repeat)
			{
				_a = a * a - b * b + c.r;
				_b = 2 * a * b + c.i;
				a = _a;
				b = _b;
				if (a * a + b * b >= 4)
				{
					my_mlx_pixel_put(img, i, j, 0x00FF0000);
					break;
				}
				k++;
			}
			j += 1;
		}
		i += 1;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return ;
}

void	plot_mandelbrot()
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "mandelbrot");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.magnification_rate = 1.0;
	drow_mandelbrot(&img, img.magnification_rate);

	mlx_hook(img.mlx_win,  2, (1L <<  0), hanle_key_press, &img);
	mlx_hook(img.mlx_win, 17, (1L << 16), close_window,    &img);
	mlx_hook(img.mlx_win,  4, (1L <<  2), mouse_down,      &img);

	mlx_loop(img.mlx);

	return ;
}
