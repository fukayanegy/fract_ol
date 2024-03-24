/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:16:48 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/24 15:11:20 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

int	minimize_hook(int keycode, t_data *img)
{
	drow_mandelbrot(img);
	return (1);
	(void)keycode;
	(void)img;
}
