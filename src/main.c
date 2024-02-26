/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/26 19:18:55 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fract_ol.h"

static int	check_correct_args(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 10 && !ft_strncmp(argv[1], "mandelbrot", 10))
			return (-1);
	}
	else if (argc == 4)
	{
		if (ft_strlen(argv[1]) == 5 && !ft_strncmp(argv[1], "julia", 5))
			return (0);
	}
	return (2);
}

static int	check_correct_julia_args(t_comp *c)
{
	if (-2 > c->r || c->r > 2)
		return (1);
	if (-1.5 > c->i || c->i > 1.5)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_comp	*c;
	int		args_type;

	args_type = check_correct_args(argc, argv);
	if (args_type == -1)
	{
		plot_mandelbrot();
	}
	else if (args_type == 0)
	{
		c = init_comp(ft_atof(argv[2]), ft_atof(argv[3]));
		if (check_correct_julia_args(c))
			exit(1);
		plot_julia(c);
	}
	else if (args_type == 1)
		return (error_code_1());
	else if (args_type == 2)
		return (error_code_2());
	return (0);
}
