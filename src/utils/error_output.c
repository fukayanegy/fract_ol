/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:56:24 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/04 13:56:01 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

int	error_code_1(void)
{
	ft_putstr_fd("\033[31m", 1);
	ft_putstr_fd("Error Code:1\n", 2);
	ft_putstr_fd("Parameters Not Found.\n", 2);
	ft_putstr_fd("Only parameters 'mandelbrot' or 'julia'.\n", 2);
	ft_putstr_fd("\033[0m", 1);
	return (1);
}

int	error_code_2(void)
{
	ft_putstr_fd("\033[31m", 1);
	ft_putstr_fd("Error Code:2\n", 2);
	ft_putstr_fd("Wrong Format\n", 2);
	ft_putstr_fd("\033[02m", 1);
	ft_putstr_fd("\033[32m", 1);
	ft_putstr_fd("The two allowed formats are\n", 2);
	ft_putstr_fd("1. mandelbrot\n", 2);
	ft_putstr_fd("2. julia real_part imaginary_part\n", 2);
	ft_putstr_fd("\033[02m", 1);
	return (1);
}

int	error_code_3(void)
{
	ft_putstr_fd("\033[31m", 1);
	ft_putstr_fd("Error Code:3\n", 2);
	ft_putstr_fd("Wrong julia parameters\n", 2);
	ft_putstr_fd("\033[02m", 1);
	ft_putstr_fd("\033[32m", 1);
	ft_putstr_fd("julia parameters range is\n", 2);
	ft_putstr_fd("-1 < para < 1\n", 2);
	ft_putstr_fd("\033[02m", 1);
	return (1);
}
