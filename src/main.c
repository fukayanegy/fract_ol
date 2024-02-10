/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/10 19:01:37 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"
# include <libc.h>

int	main(int argc, char **argv)
{
	t_complex *c;

	c = NULL;
	if (!(argc == 2 || argc == 4))
		return (0);
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
	{
		plot_mandelbrot();
		exit(0);
	}
	else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
	{
		if (argc != 4)
			return (0);
		c = init_complex(ft_atof(argv[2]), ft_atof(argv[3]));
		if (c->r == 0 || c->i == 0)
			exit(0);
		plot_julia(c);
	}
	else
		printf("What is this?\n");
	printf("main finish.\n");
	exit(0);
}

__attribute__((destructor))
static void destructor()
{
    system("leaks -q fract_al");
}
