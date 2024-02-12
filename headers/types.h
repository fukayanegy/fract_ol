/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:33:48 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/12 18:53:28 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*
 * r : real part
 * i : imaginary part
 */
typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_color;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*mlx_data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	bool		is_mandelbrot;
	double		magnification_rate;
	t_complex	*c;
}				t_data;

#endif
