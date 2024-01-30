/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:01:06 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/30 15:42:44 by etakaham         ###   ########.fr       */
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
	}
	return (0);
}

int	mouse_down(int keycode, t_data *img)
{
	if (keycode == 5)
	{
		printf("mouse_up\n");
		//mlx_destroy_image(img->mlx, img->img);
		//drow_mandelbrot(img, 0.5);
	}
	if (keycode == 4)
	{
		printf("mouse_down\n");
		//mlx_destroy_image(img->mlx, img->img);
		//drow_mandelbrot(img, 1.5);
	}
	(void) img;
	return (0);
}