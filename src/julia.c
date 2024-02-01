/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:46 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/01 16:54:04 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	julia(void)
{
	return ;
}

void	drow_julia(t_data *img, t_complex c, int magnification_rate)
{
	double	xS  = -1.5;
	double	xE  =  1.5;
	double	yS  = -1.5;
	double	yE  =  1.5;
	double	Cr  = -0.3;
	double	Ci  = -0.63;
	double	imax= 400;
	double	E   = 4.0;
	double	dx, dy;
	double	x0,y0,x,y,xN,yN;
	t_color	result;
	int		i,j,ix,iy,k,cl,nc;

	dx=(xE-xS)/WIDTH;
	dy=(yE-yS)/HEIGHT;
	nc=imax/256; if ( nc<=0 ) nc=1;

	y0 = yS;
	i = 0;
	iy=WIDTH;
	while (i < WIDTH)
	{
		x0 = xS;
		j = 0;
		ix = 0;
		while (j < HEIGHT)
		{
			x = x0; y = y0;
			k = 0;
			while (k < imax)
			{
				xN=x*x-y*y+Cr;
				yN=2*x*y+Ci;
				if (xN*xN+yN*yN>E) break;
				x=xN; y=yN;
				k++;
			}
			cl=k/nc;
			if ( cl>255 ) cl=255;
			result.red = cl;
			result.green = cl;
			result.blue = cl;
			my_mlx_pixel_put(img, ix, iy, ft_rgb(&result));

			x0 += dx;
			j++;
			ix++;
		}
		y0 += dy;
		i++;
		iy--;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	return ;
	(void)magnification_rate;
	(void)c;
}

void	plot_julia()
{
	t_data	img;
	t_complex	c;

	c.r = -0.7;
	c.i = 0.27;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "julia");
	img.img_ptr = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.mlx_data_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	drow_julia(&img, c, 1.0);
	mlx_hook(img.win_ptr, 2, 1L<<0, hanle_key_press, &img);
	mlx_hook(img.win_ptr, 17, 0, close_window, &img);
	mlx_loop(img.mlx_ptr);
	return ;
}
