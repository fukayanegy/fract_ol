/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:33:45 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 18:39:22 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*mandelbrot*/
void			drow_mandelbrot(t_data *img, double magnification_rate);
void			plot_mandelbrot(void);

/*julia*/
void			drow_julia(t_data *img);
void			plot_julia(t_comp *c);

double			ft_atof(const char *str);

void			comp_add(t_comp *a, t_comp *b, t_comp *c);
void			comp_malt(t_comp *a, t_comp *b, t_comp *c);
void			comp_square(t_comp *comp, t_comp *squared_comp);

/*utils*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	ft_rgb(t_color *color);

// hook function
int				esc_key_hook(int keycode, t_data *img);
int				close_window_hook(int keycode, t_data *img);
int				mouse_hook(int keycode, int x, int y, t_data *img);
int			minimize_hook(int keycode, t_data *img);

// init types
void			*init_mlx_data(bool is_mandelbrot);
void			*init_comp(double real_part, double imaginary_part);
void			*init_color(unsigned char r, unsigned char g, unsigned char b);
void			init_image(t_data *img);

#endif
