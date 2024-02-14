/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:26 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 15:13:28 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	comp_add(t_complex *a, t_complex *b, t_complex *c)
{
	c->r = a->r + b->r;
	c->i = a->i + b->i;
	return ;
}
