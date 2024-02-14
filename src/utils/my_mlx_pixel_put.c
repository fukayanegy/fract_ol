# include "../../headers/fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_data_addr +
		(y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return ;
}
