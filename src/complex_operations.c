/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:35:33 by etakaham          #+#    #+#             */
/*   Updated: 2024/02/10 19:42:27 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/fract_ol.h"

void	comp_add(t_complex *a, t_complex *b, t_complex *c)
{
	c->r = a->r + b->r;
	c->i = a->i + b->i;
	return ;
}

void	comp_malt(t_complex *a, t_complex *b, t_complex *c)
{
	c->r = a->r * b->r - a->i * b->i;
	c->i = a->r * b->i + a->i * b->r;
	return ;
}

void	comp_square(t_complex *comp, t_complex *squared_comp)
{
	squared_comp->r = comp->r * comp->r - comp->i * comp->i;
	squared_comp->i = 2 * comp->r * comp->i;
	return ;
}
