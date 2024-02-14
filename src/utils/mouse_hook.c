/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:05:49 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 17:17:38 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		img->zoom_rate *= 0.9;
		if (img->is_mandelbrot == true)
			drow_mandelbrot(img, img->zoom_rate);
		else
		{
			drow_julia(img);
		}
	}
	if (keycode == 5)
	{
		img->zoom_rate *= 1.1;
		if (img->is_mandelbrot == true)
			drow_mandelbrot(img, img->zoom_rate);
		else
		{
			drow_julia(img);
		}
	}
	return (0);
}
