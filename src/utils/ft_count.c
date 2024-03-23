/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:57:35 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/23 16:03:40 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

size_t	ft_count(const char *str, char c)
{
	size_t	result;

	result = 0;
	while (*str)
	{
		if (*str == c)
			result++;
		str++;
	}
	return (result);
}
