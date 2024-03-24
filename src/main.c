/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:25 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/24 15:17:38 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fract_ol.h"

static int	is_decimal_string(const char *str)
{
	int	i;

	if (!(str[0] == 43 || str[0] == 45 || (48 <= str[0] && str[0] <= 57)))
		return (1);
	i = 1;
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.'))
			return (1);
		if (ft_count(str, '.') > 1)
			return (1);
		i++;
	}
	return (0);
}

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
		{
			if (is_decimal_string(argv[2]))
				return (1);
			if (is_decimal_string(argv[3]))
				return (1);
			return (0);
		}
	}
	return (2);
}

static int	check_correct_julia_args(t_comp *c)
{
	if (-1.5 >= c->r || c->r >= 1.5)
		return (1);
	if (-1.5 >= c->i || c->i >= 1.5)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_comp	*c;
	int		args_type;

	args_type = check_correct_args(argc, argv);
	if (args_type == -1)
		plot_mandelbrot();
	else if (args_type == 0)
	{
		c = init_comp(ft_atof(argv[2]), ft_atof(argv[3]));
		printf("r : %f\ni : %f\n", c->r, c->i);
		if (check_correct_julia_args(c))
		{
			free(c);
			error_code_3();
			exit(1);
		}
		plot_julia(c);
	}
	else if (args_type == 1)
		return (error_code_1());
	else if (args_type == 2)
		return (error_code_2());
	return (0);
}
