/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:33:45 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/12 19:29:23 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*mandelbrot*/
void			plot_mandelbrot();

/*julia*/
int				julia(void);
void			drow_julia(t_data *img, t_complex *c, int magnification_rate);
void			plot_julia(t_complex *c);

double			ft_atof(const char *str);

void	comp_add(t_complex *a, t_complex *b, t_complex *c);
void	comp_malt(t_complex *a, t_complex *b, t_complex *c);
void	comp_square(t_complex *comp, t_complex *squared_comp);

/*utils*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				hanle_key_press(int keycode, t_data *img);
int				close_window(int keycode, t_data *img);
int				mouse_down(int keycode, int x, int y, t_data *img);
unsigned int	ft_rgb(t_color *color);
void			*init_mlx_data(bool is_mandelbrot);
void			*init_complex(double real_part, double imaginary_part);
void			*init_color(unsigned char red,
							unsigned char green,
							unsigned char blue);
void			init_image(t_data *img);


/*main*/
void			drow_mandelbrot(t_data *img, double magnification_rate);
void			plot_mandelbrot();

#endif
