/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_malt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:13:16 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/14 15:13:21 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fract_ol.h"

void	comp_malt(t_complex *a, t_complex *b, t_complex *c)
{
	c->r = a->r * b->r - a->i * b->i;
	c->i = a->r * b->i + a->i * b->r;
	return ;
}
