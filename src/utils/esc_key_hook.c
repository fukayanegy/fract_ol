# include "../../headers/fract_ol.h"

int	esc_key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		exit(0);
	}
	return (0);
}
