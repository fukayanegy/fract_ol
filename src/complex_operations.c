/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:35:33 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/01 19:03:35 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

t_complex	*comp_add(t_complex *a, t_complex *b)
{
	t_complex	*result;

	result = malloc(sizeof(t_complex));
	if (result == NULL)
		return (NULL);
	result->r = a->r + b->r;
	result->i = a->i + b->i;
	return (result);
}

t_complex	*comp_malt(t_complex *a, t_complex *b)
{
	t_complex	*result;

	result = malloc(sizeof(t_complex));
	if (result == NULL)
		return (NULL);
	result->r = a->r * b->r - a->i * b->i;
	result->i = a->r * b->i + a->i * b->r;
	return (result);
}

t_complex	*comp_square(t_complex *comp)
{
	t_complex	*result;

	result = malloc(sizeof(t_complex));
	if (result == NULL)
		return (NULL);
	result->r = comp->r * comp->r - comp->i * comp->i;
	result->i = 2 * comp->r * comp->i;
	return (result);
}

double	comp_abs(t_complex *comp)
{
	double	result;

	result = sqrt((comp->r * comp->r) - (comp->i * comp->i));
	return (result);
}
