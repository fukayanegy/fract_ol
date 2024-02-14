# include "../../headers/fract_ol.h"

void	comp_add(t_complex *a, t_complex *b, t_complex *c)
{
	c->r = a->r + b->r;
	c->i = a->i + b->i;
	return ;
}
