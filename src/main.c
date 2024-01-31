/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/31 16:22:54 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//  plot_mandelbrot();
	plot_julia();
	printf("success!\n");

	return (0);
}
