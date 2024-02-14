# include "../../headers/fract_ol.h"

void	comp_square(t_complex *comp, t_complex *squared_comp)
{
	squared_comp->r = comp->r * comp->r - comp->i * comp->i;
	squared_comp->i = 2 * comp->r * comp->i;
	return ;
}
