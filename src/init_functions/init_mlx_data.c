/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:36:01 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 15:12:17 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	*init_mlx_data(bool is_mandelbrot)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		exit(0);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, WIN_NAME);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->mlx_data_addr = mlx_get_data_addr(data->img_ptr,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	data->is_mandelbrot = is_mandelbrot;
	return (data);
}
