# include "../../headers/fract_ol.h"

unsigned int ft_rgb(t_color *color)
{
	return (color->red << 16) | (color->green << 8) | color->blue;
}