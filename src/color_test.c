/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:11:45 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/01 16:12:20 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

int	main(void)
{
	t_color rgb;
	rgb.red   = 255;
	rgb.green = 255;
	rgb.blue  = 255;
	unsigned int result = ft_rgb(&rgb);
	printf("RGB: (%u, %u, %u) -> 0x%08X\n", rgb.red, rgb.green, rgb.blue, result);
	return (0);
}
