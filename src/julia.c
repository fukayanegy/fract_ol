/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:46 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/13 12:58:14 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

int	julia(void)
{
	int	result;
	result = 0;
	/*
	int	x;
	int	y;
	int	xN;
	int	yN;

	while (result < JULIA_REPEAT)
	{
		xN = x * x - y * y + c->r;
		yN = 2 * x * y + c->i;
		if (xN * xN + yN * yN > E)
			break ;
		result++;
	}
	if (result > 255)
		return (255);
	*/
	return (result) ;
}

void	drow_julia(t_data *img, t_complex *c, double magnification_rate)
{
	int			i;
	int			j;
	int			k;
	int			nc;
	double		dx, dy;
	t_complex	*start;       // xS, yS
	t_complex	*end;         // xE, yE
	t_complex	*pixel_count; // x0, y0
	t_complex	*z;           // x , y
	t_complex	*tmp;         // xN, yN
	t_color		*result;

	start = init_complex((-1.5 * magnification_rate), (-1.5 * magnification_rate));
	end = init_complex((1.5 * magnification_rate), (1.5 * magnification_rate));
	pixel_count = init_complex(0.0, 0.0);
	z = init_complex(0.0, 0.0);
	tmp = init_complex(0.0, 0.0);
	dx = (end->r - start->r) / WIDTH;
	dy = (end->i - start->i) / HEIGHT;
	nc = JULIA_REPEAT / 256;
	pixel_count->i = start->i;
	j = WIDTH;
	while (j > 0)
	{
		pixel_count->r = start->r;
		i = 0;
		while (i < HEIGHT)
		{
			z->r = pixel_count->r;
			z->i = pixel_count->i;
			k = 0;
			while (k < JULIA_REPEAT)
			{
				comp_square(z, tmp);
				comp_add(tmp, c, z);
				if (z->r * z->r + z->i * z->i > E)
					break;
				k++;
			}
			if ( k > 255 )
				k = 255;
			result = init_color(k, k, k);
			my_mlx_pixel_put(img, i, j, ft_rgb(result));
			free(result);
			pixel_count->r += dx;
			i++;
		}
		pixel_count->i += dy;
		j--;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	free(start);
	free(end);
	free(pixel_count);
	free(z);
	free(tmp);
	return ;
	(void)magnification_rate;
}

void	plot_julia(t_complex *c)
{
	t_data	*img;

	img = init_mlx_data(false);
	img->magnification_rate = 1.0;
	img->c = init_complex(c->r, c->i);
	drow_julia(img, c, 1.0);
	mlx_hook(img->win_ptr, 2, 1L<<0, esc_key_hook, img);
	mlx_hook(img->win_ptr, 17, 0, close_window_hook, img);
	mlx_hook(img->win_ptr,  4, (1L <<  2), mouse_hook, img);
	mlx_loop(img->mlx_ptr);
	free(img->mlx_ptr);
	free(img->win_ptr);
	free(img->img_ptr);
	free(img->mlx_data_addr);
	free(img->c);
	free(img);
}
