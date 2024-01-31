/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:01:06 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/31 16:01:51 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return ;
}

int	hanle_key_press(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return (0);
}

int	close_window(int keycode, t_data *img)
{
	(void)keycode;
	(void)img;
	exit(0);
}

int	mouse_up(int keycode, t_data *img)
{
	(void) img;
	if (keycode == 5)
	{
		printf("mouse_up\n");
		drow_mandelbrot(img, 1.5);
	}
	return (0);
}

int	mouse_down(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		img->magnification_rate *= 0.9;
		drow_mandelbrot(img, img->magnification_rate);
	}
	if (keycode == 5)
	{
		img->magnification_rate *= 1.1;
		drow_mandelbrot(img, img->magnification_rate);
	}
	return (0);
}
