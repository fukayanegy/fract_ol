/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:33:45 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/26 15:55:21 by etakaham         ###   ########.fr       */
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

#endif
