/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:08 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/12 16:47:03 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

int	drow_mandelbrot(t_data *img)
{
	t_comp		*start;
	t_comp		*end;
	t_comp		*C;
	t_comp		*dC;
	t_comp		*z;
	t_comp		*zN;
	t_comp		*tmp;
	t_color		*color;
	int			i, ix, iy, cl, nc;

	start = init_comp((-2.3 * img->zoom_rate), (-1.5 * img->zoom_rate));
	end = init_comp((0.7 * img->zoom_rate), (1.5 * img->zoom_rate));
	C = init_comp(0.0, 0.0);
	dC = init_comp((end->r - start->r) / WIDTH, (end->i - start->i) / HEIGHT);
	z = init_comp(0.0, 0.0);
	zN = init_comp(0.0, 0.0);
	tmp = init_comp(0.0, 0.0);
	nc = MANDELBROT_REPEAT / 256;
	if (nc <= 0)
		nc = 1;

	for (C->i = start->i, iy=HEIGHT; C->i <= end->i; C->i += dC->i, iy--)
	{
		for (C->r = start->r, ix=0; C->r <= end->r; C->r += dC->r, ix++)
		{
			z->i = 0.0;
			z->r = 0.0;
			for (i = 0; i < MANDELBROT_REPEAT; i++)
			{
				comp_square(z, tmp);
				comp_add(tmp, C, zN);
				if (zN->r > E || zN->i > E)
				{
					break;
				}
				z->r = zN->r;
				z->i = zN->i;
			}
			cl = i / nc;
			if (cl > 255)
				cl = 255;
			color = init_color(cl, cl, cl);
			my_mlx_pixel_put(img, ix, iy, ft_rgb(color));
			free(color);
		}
	}

	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	free(start);
	free(end);
	free(C);
	free(dC);
	free(z);
	free(zN);
	free(tmp);
	return (0);
}
