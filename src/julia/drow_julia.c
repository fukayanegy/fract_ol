/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:59 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/23 12:52:46 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

static t_color	*julia(t_comp *c, t_comp *z)
{
	int			k;
	t_color		*result;
	t_comp		*tmp;

	tmp = init_comp(0.0, 0.0);
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

static unsigned int	tmp_name(t_comp *pixel_count, t_comp *c)
{
	t_comp			*z;
	t_color			*color;
	unsigned int	color_signal;

	z = init_comp(0.0, 0.0);
	z->r = pixel_count->r;
	z->i = pixel_count->i;
	color = julia(c, z);
	color_signal = ft_rgb(color);
	free(z);
	free(color);
	return (color_signal);
}

static void	free_comps(t_comp *a, t_comp *b, t_comp *c, t_comp *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
}

static void	support(t_comp *s, t_comp *r, t_comp *p, t_data *img)
{
	int				i;
	int				j;
	unsigned int	color_signal;

	p->i = s->i;
	j = 0;
	while (j < WIDTH)
	{
		p->r = s->r;
		i = 0;
		while (i < HEIGHT)
		{
			color_signal = tmp_name(p, img->c);
			my_mlx_pixel_put(img, i, j, color_signal);
			p->r += r->r;
			i++;
		}
		p->i += r->i;
		j++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
}

int	drow_julia(t_data *img)
{
	t_comp		*start;
	t_comp		*end;
	t_comp		*render_pn;
	t_comp		*pixel_count;

	start = init_comp((-1.5 * img->zoom_rate), (-1.5 * img->zoom_rate));
	end = init_comp((1.5 * img->zoom_rate), (1.5 * img->zoom_rate));
	render_pn = init_comp(0.0, 0.0);
	render_pn->r = (end->r - start->r) / WIDTH;
	render_pn->i = (end->i - start->i) / HEIGHT;
	pixel_count = init_comp(0.0, 0.0);
	support(start, render_pn, pixel_count, img);
	free_comps(start, end, render_pn, pixel_count);
	return (0);
}
