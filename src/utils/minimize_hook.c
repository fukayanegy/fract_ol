/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:16:48 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/23 12:41:48 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

int	minimize_hook(int keycode, t_data *img)
{
	printf("======================\n");
	printf("minimize!\n");
	printf("img is %p\n", img);
	printf("keycode is %d\n", keycode);
	printf("======================\n");
	drow_mandelbrot(img);
	return (1);
	(void)keycode;
	(void)img;
}
