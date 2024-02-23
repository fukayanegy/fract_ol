/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:14 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/23 12:46:51 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	plot_mandelbrot(void)
{
	t_data	*img;

	img = init_mlx_data(true);
	img->zoom_rate = 1.0;
	drow_mandelbrot(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	mlx_hook(img->win_ptr, 2, (1L << 0), esc_key_hook, img);
	mlx_hook(img->win_ptr, 4, (1L << 2), mouse_hook, img);
	mlx_hook(img->win_ptr, 17, (1L << 16), close_window_hook, img);
	mlx_loop_hook(img->mlx_ptr, drow_mandelbrot, img);
	mlx_loop(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img->win_ptr);
	free(img->img_ptr);
	free(img->mlx_data_addr);
	free(img);
}
