/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:08 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/20 20:30:10 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

static void	free_comps(t_comp *a, t_comp *b, t_comp *c)
{
	free(a);
	free(b);
	free(c);
}

static t_color	*mandelbrot(t_comp *c)
{
	t_comp	*z;
	t_comp	*new_z;
	t_comp	*tmp;
	t_color	*color;
	int		i;

	z = init_comp(0.0, 0.0);
	new_z = init_comp(0.0, 0.0);
	tmp = init_comp(0.0, 0.0);
	i = 0;
	while (i < MANDELBROT_REPEAT)
	{
		comp_square(z, tmp);
		comp_add(tmp, c, new_z);
		if (new_z->r > E || new_z->i > E)
			break ;
		z->r = new_z->r;
		z->i = new_z->i;
		i++;
	}
	color = init_color(i, i, i);
	free_comps(z, new_z, tmp);
	return (color);
}

static void	support(t_comp *start, t_comp *end, t_comp *render_pn, t_data *img)
{
	int			i;
	int			j;
	t_comp		*c;
	t_color		*color;

	i = WIDTH;
	c = init_comp(0.0, 0.0);
	c->i = start->i;
	while (c->i <= end->i)
	{
		j = 0;
		c->r = start->r;
		while (c->r <= end->r)
		{
			color = mandelbrot(c);
			my_mlx_pixel_put(img, j++, i, ft_rgb(color));
			free(color);
			c->r += render_pn->r;
		}
		c->i += render_pn->i;
		i--;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	free(c);
}

int	drow_mandelbrot(t_data *img)
{
	t_comp		*start;
	t_comp		*end;
	t_comp		*render_pn;

	start = init_comp((-2.3 * img->zoom_rate), (-1.5 * img->zoom_rate));
	end = init_comp((0.7 * img->zoom_rate), (1.5 * img->zoom_rate));
	render_pn = init_comp(0.0, 0.0);
	render_pn->r = (end->r - start->r) / WIDTH;
	render_pn->i = (end->i - start->i) / HEIGHT;
	support(start, end, render_pn, img);
	free_comps(start, end, render_pn);
	return (0);
}
