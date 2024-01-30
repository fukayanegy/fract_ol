/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:33:45 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/30 14:53:38 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

int		mandelbrot(int n, double *comp);
void	plot_mandelbrot();
void	julia(void);
double	ft_atof(const char *str);

t_complex	*comp_add(t_complex *a, t_complex *b);
t_complex	*comp_malt(t_complex *a, t_complex *b);
double		comp_abs(t_complex *comp);

/*utils*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	hanle_key_press(int keycode, t_data *img);
int	close_window(int keycode, t_data *img);
int	mouse_up(int keycode, t_data *img);
int	mouse_down(int keycode, t_data *img);

/*main*/
void	drow_mandelbrot(t_data *img, double magnification_rate);
void	plot_mandelbrot();



#endif
