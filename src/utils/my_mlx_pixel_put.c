/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:06:34 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 17:37:37 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	size_t	tmp;

	tmp = x * (data->bits_per_pixel / 8);
	dst = data->mlx_data_addr + (y * data->size_line + tmp);
	*(unsigned int *) dst = color;
	return ;
}
