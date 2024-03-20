/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:34:10 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/20 20:22:44 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	*init_comp(double real_part, double imaginary_part)
{
	t_comp	*comp;

	comp = malloc(sizeof(t_comp));
	if (!comp)
		exit(1);
	comp->r = real_part;
	comp->i = imaginary_part;
	return (comp);
}
