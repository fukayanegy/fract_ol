/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:01:06 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/13 12:56:26 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_data_addr +
		(y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return ;
}

int	esc_key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_window_hook(int keycode, t_data *img)
{
	(void)keycode;
	(void)img;
	exit(0);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		img->magnification_rate *= 0.9;
		if (img->is_mandelbrot == true)
			drow_mandelbrot(img, img->magnification_rate);
		else
		{
			drow_julia(img, img->c, img->magnification_rate);
		}
	}
	if (keycode == 5)
	{
		img->magnification_rate *= 1.1;
		if (img->is_mandelbrot == true)
			drow_mandelbrot(img, img->magnification_rate);
		else
		{
			drow_julia(img, img->c, img->magnification_rate);
		}
	}
	return (0);
}

unsigned int ft_rgb(t_color *color)
{
	return (color->red << 16) | (color->green << 8) | color->blue;
}
