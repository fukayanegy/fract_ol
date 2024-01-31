/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:46 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/31 16:25:30 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	julia(void)
{
	return ;
}

void	drow_julia(t_data *img, int magnification_rate)
{
	(void)img;
	(void)magnification_rate;
	return ;
}

void	plot_julia()
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "julia");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drow_julia(&img, 1.0);
	mlx_hook(img.mlx_win, 2, 1L<<0, hanle_key_press, &img);
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
	return ;
}
