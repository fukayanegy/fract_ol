/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:34:10 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/01 17:38:01 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/fract_ol.h"

void	*init_complex(double real_part, double imaginary_part)
{
	t_complex	*comp;

	if (!(comp = malloc(sizeof(*comp))))
		exit(0);
	comp->r = real_part;
	comp->i = imaginary_part;
	return (comp);
}