/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 13:33:27 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"
# include <libc.h>

int	main(int argc, char **argv)
{
	t_complex *c;

	c = NULL;
	if (!(argc == 2 || argc == 4))
	{
		write(1, ERROR_STRING, 56);
		return (1);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
	{
		plot_mandelbrot();
	}
	else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
	{
		if (argc != 4)
		{
			write(1, ERROR_STRING, 56);
			return (1);
		}
		c = init_complex(ft_atof(argv[2]), ft_atof(argv[3]));
		plot_julia(c);
	}
	else
	{
		write(1, ERROR_STRING, 56);
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	char test1[] = "123456789.0123456789";
	char test2[] = "0.0";
	char test3[] = "123";
	char test4[] = ".0012";
	if (atof(test1) == ft_atof(test1))
		printf("test1 is OK\n");
	if (atof(test2) == ft_atof(test2))
		printf("test2 is OK\n");
	if (atof(test3) == ft_atof(test3))
		printf("test3 is OK\n");
	if (atof(test4) == ft_atof(test4))
		printf("test4 is OK\n");
	else
		printf("ori is\t\t%f\nmy_func is\t%f\n", atof(test4), ft_atof(test4));

	return 0;
}
*/

__attribute__((destructor))
static void destructor()
{
    system("leaks -q fract_al");
}
