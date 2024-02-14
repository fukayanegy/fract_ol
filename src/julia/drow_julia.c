/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:59 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 17:13:36 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

static t_color	*julia(t_complex *c, t_complex *z)
{
	int			k;
	t_color		*result;
	t_complex	*tmp;

	tmp = init_complex(0.0, 0.0);
	k = 0;
	while (k < JULIA_REPEAT)
	{
		comp_square(z, tmp);
		comp_add(tmp, c, z);
		if (z->r * z->r + z->i * z->i > E)
			break ;
		k++;
	}
	if (k > 255)
		k = 255;
	result = init_color(k, k, k);
	free(tmp);
	return (result);
}

static unsigned int	tmp_name(t_complex *pixel_count, t_complex *c)
{
	t_complex		*z;
	t_color			*color;
	unsigned int	color_signal;

	z = init_complex(0.0, 0.0);
	z->r = pixel_count->r;
	z->i = pixel_count->i;
	color = julia(c, z);
	color_signal = ft_rgb(color);
	free(z);
	free(color);
	return (color_signal);
}

static void	free_comps(t_complex *a, t_complex *b)
{
	free(a);
	free(b);
}

static void	drow_julia_support(t_complex *start, t_complex *end, t_data *img)
{
	int				i;
	int				j;
	unsigned int	color_signal;
	t_complex		*render_pn;
	t_complex		*pixel_count;

	render_pn = init_complex(0.0, 0.0);
	render_pn->r = (end->r - start->r) / WIDTH;
	render_pn->i = (end->i - start->i) / HEIGHT;
	pixel_count = init_complex(0.0, 0.0);
	pixel_count->i = start->i;
	j = 0;
	while (j < WIDTH)
	{
		pixel_count->r = start->r;
		i = 0;
		while (i < HEIGHT)
		{
			color_signal = tmp_name(pixel_count, img->c);
			my_mlx_pixel_put(img, i, j, color_signal);
			pixel_count->r += render_pn->r;
			i++;
		}
		pixel_count->i += render_pn->i;
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	free_comps(render_pn, pixel_count);
}

void	drow_julia(t_data *img)
{
	t_complex		*start;
	t_complex		*end;

	start = init_complex((-1.5 * img->zoom_rate), (-1.5 * img->zoom_rate));
	end = init_complex((1.5 * img->zoom_rate), (1.5 * img->zoom_rate));
	drow_julia_support(start, end, img);
	free_comps(start, end);
}
