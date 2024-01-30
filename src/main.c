/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/30 13:58:05 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	plot_mandelbrot();
	// plot_julia();
	printf("success!\n");

	return (0);
}
