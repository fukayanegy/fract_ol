/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/26 16:09:22 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	double	comp[] = {1.2, 2.3};
	mandelbrot(5, comp);
	plot_mandelbrot();
	printf("success!\n");

	return (0);
}
