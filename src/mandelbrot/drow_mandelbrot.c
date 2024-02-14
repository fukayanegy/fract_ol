/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:08 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 15:17:48 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

static void	mandelbrot(t_complex *c, t_data *img, int i, int j)
{
	int			k;
	t_complex	*z;
	t_complex	*tmp;

	z = init_complex(0.0, 0.0);
	tmp = init_complex(0.0, 0.0);
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

void	drow_mandelbrot(t_data *img, double magnification_rate)
{
	int			i;
	int			j;
	t_complex	*c;

	c = init_complex(0.0, 0.0);
	i = 0;
	while (i < WIDTH)
	{
		c->r = ((double)i * 4 / WIDTH - 4 / 2) * magnification_rate;
		j = 0;
		while (j < HEIGHT)
		{
			c->i = ((double)j * 4 / HEIGHT - 4 / 2) * magnification_rate;
			my_mlx_pixel_put(img, i, j, 0x00FFFFFF);
			mandelbrot(c, img, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	free(c);
}