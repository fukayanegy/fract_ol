/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:24:38 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 17:44:48 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	*init_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	*color;

	color = malloc(sizeof(*color));
	if (!color)
		exit(0);
	color->red = r;
	color->green = g;
	color->blue = b;
	return (color);
}
