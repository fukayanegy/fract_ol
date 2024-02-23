/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:16:54 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/23 13:12:18 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	plot_julia(t_comp *c)
{
	t_data	*img;

	img = init_mlx_data(false);
	img->zoom_rate = 1.0;
	img->c = init_comp(c->r, c->i);
	drow_julia(img);
	mlx_hook(img->win_ptr, 2, (1L << 0), esc_key_hook, img);
	mlx_hook(img->win_ptr, 17, 0, close_window_hook, img);
	mlx_hook(img->win_ptr, 4, (1L << 2), mouse_hook, img);
	mlx_loop_hook(img->mlx_ptr, drow_julia, img);
	mlx_loop(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img->win_ptr);
	free(img->img_ptr);
	free(img->mlx_data_addr);
	free(img->c);
	free(img);
}
