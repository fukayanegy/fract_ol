/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:32:39 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/23 18:09:52 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

static int	skip_space(const char *str)
{
	int	not_space_index;

	not_space_index = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
	{
		not_space_index++;
		str++;
	}
	return (not_space_index);
}

static char	**split_fraction_str(const char *str)
{
	char	**result;
	int		counter;
	int		i;

	if (*str == '\0')
		return (NULL);
	result = ft_split(str, '.');
	counter = 0;
	while (result[counter] != NULL)
	{
		i = 0;
		while (result[counter][i] != '\0')
		{
			if (!ft_isdigit(result[counter][i]))
				return (NULL);
			i++;
		}
		counter++;
	}
	if (counter > 2)
		return (NULL);
	return (result);
}

static double	calculate_decimal(const char *str)
{
	double	decimal;
	int		i;

	if (str == NULL)
		return (0);
	decimal = 0;
	i = ft_strlen(str) - 1;
	while (ft_isdigit(str[i]))
	{
		decimal += str[i] - '0';
		decimal /= 10;
		i--;
	}
	return (decimal);
}

static void	free_splited_str(char **splited_str)
{
	int		i;

	i = 0;
	while (splited_str[i] != NULL)
		free(splited_str[i++]);
	free(splited_str);
}

double	ft_atof(const char *str)
{
	double	result;
	bool	is_positive;
	int		index;
	char	**splited_str;

	index = skip_space(str);
	is_positive = !(str[index] == '-');
	if (!ft_isdigit(str[index]))
		index++;
	splited_str = split_fraction_str(&str[index]);
	if (splited_str == NULL)
	{
		error_code_3();
		exit(1);
	}
	result = ft_atoi(splited_str[0]) + calculate_decimal(splited_str[1]);
	if (is_positive == false)
		result *= -1;
	free_splited_str(splited_str);
	return (result);
}
