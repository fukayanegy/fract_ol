/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:53 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/01 19:29:24 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	mandelbrot(t_complex *c, t_data *img, int i, int j)
{
	int	k;
	int	repeat = 50;
	t_complex	*z;

	z = init_complex(0.0, 0.0);
	k = 0;
	while (k < repeat)
	{
		z = comp_add(comp_square(z), c);
		if (z->r * z->r + z->i * z->i > 4)
		{
			my_mlx_pixel_put(img, i, j, 0x00000000);
			break;
		}
		k++;
	}
}

void	drow_mandelbrot(t_data *img, double magnification_rate)
{
	int	i, j;
	t_complex	*c;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}

	c = init_complex(0.0, 0.0);

	i = 0;
	while (i < WIDTH)
	{
		c->r = ((double)i * 4 / WIDTH - 4 / 2) * magnification_rate;
		j = 0;
		while (j < HEIGHT)
		{
			c->i = ((double)j * 4 / HEIGHT - 4 / 2) * magnification_rate;
			mandelbrot(c, img, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	return ;
}

void	plot_mandelbrot()
{
	t_data	*img;

	img = init_mlx_data(true);
	img->magnification_rate = 1.0;
	drow_mandelbrot(img, img->magnification_rate);
	mlx_hook(img->win_ptr,  2, (1L <<  0), hanle_key_press, img);
	mlx_hook(img->win_ptr, 17, (1L << 16), close_window,    img);
	mlx_hook(img->win_ptr,  4, (1L <<  2), mouse_down,      img);
	mlx_loop(img->mlx_ptr);
	return ;
}
