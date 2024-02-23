/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:08 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/23 12:49:40 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

static void	mandelbrot(t_comp *c, t_data *img, int i, int j)
{
	int		k;
	t_comp	*z;
	t_comp	*tmp;

	z = init_comp(0.0, 0.0);
	tmp = init_comp(0.0, 0.0);
	k = 0;
	while (k < MANDELBROT_REPEAT)
	{
		comp_square(z, tmp);
		comp_add(tmp, c, z);
		if (z->r * z->r + z->i * z->i > E)
		{
			my_mlx_pixel_put(img, i, j, 0x00000000);
			break ;
		}
		k++;
	}
	free(z);
	free(tmp);
}

int	drow_mandelbrot(t_data *img)
{
	int		i;
	int		j;
	t_comp	*c;

	c = init_comp(0.0, 0.0);
	i = 0;
	while (i < WIDTH)
	{
		c->r = ((double)i * 4 / WIDTH - 4 / 2) * img->zoom_rate;
		j = 0;
		while (j < HEIGHT)
		{
			c->i = ((double)j * 4 / HEIGHT - 4 / 2) * img->zoom_rate;
			my_mlx_pixel_put(img, i, j, 0x00FFFFFF);
			mandelbrot(c, img, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	free(c);
	return (0);
}
