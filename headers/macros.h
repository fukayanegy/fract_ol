/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:01:47 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/10 21:20:31 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define HEIGHT 1080.0
# define WIDTH 1080.0
# define MANDELBROT_REPEAT 50
# define JULIA_REPEAT 400
# define E 4
# define X_START -1.5
# define X_END 1.5
# define Y_START -1.5
# define Y_END 1.5
# define DX ((X_END - X_START) / WIDTH)
# define DY ((Y_END - Y_START) / HEIGHT)
# define WIN_NAME "fract_ol"

#endif
