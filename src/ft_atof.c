/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:39 by etakaham          #+#    #+#             */
/*   Updated: 2024/01/15 17:34:35 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

/*
static bool	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static bool	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}
*/

double	ft_atof(const char *str)
{
	double	result;
	bool	is_positive;
	int			integral;
	double		decimal;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '+')
			is_positive = true;
		else
			is_positive = false;
		str++;
	}
	else
		is_positive = true;

	integral = 0;
	while ('0' <= *str && *str <= '9')
	{
		integral *= 10;
		integral += *str - '0';
		str++;
	}
	if (*str == '.')
		str++;
	else
	{
		result = (double)integral;
		if (is_positive == false)
			result *= -1;
		return (result);
	}
	decimal = 0;
	size_t i;
	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		decimal *= 10;
		decimal += *str - '0';
		str++;
		i++;
	}
	decimal = decimal / pow(10.0, (double)i);
	result = integral + decimal;
	if (is_positive == false)
		result *= -1;
	return (result);
}
