# include "../../headers/fract_ol.h"

void	comp_malt(t_complex *a, t_complex *b, t_complex *c)
{
	c->r = a->r * b->r - a->i * b->i;
	c->i = a->r * b->i + a->i * b->r;
	return ;
}
