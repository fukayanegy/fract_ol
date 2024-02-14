/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:24:38 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 15:11:17 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	*init_color(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color	*color;

	color = malloc(sizeof(*color));
	if (!color)
		exit(0);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (color);
}
