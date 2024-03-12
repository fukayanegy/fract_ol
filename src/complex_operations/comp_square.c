/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:26 by etakaham          #+#    #+#             */
/*   Updated: 2024/03/12 14:56:31 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	comp_square(t_comp *comp, t_comp *squared_comp)
{
	squared_comp->r = comp->r * comp->r - comp->i * comp->i;
	squared_comp->i = 2 * comp->r * comp->i;
	return ;
}
