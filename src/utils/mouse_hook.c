# include "../../headers/fract_ol.h"

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		img->magnification_rate *= 0.9;
		if (img->is_mandelbrot == true)
			drow_mandelbrot(img, img->magnification_rate);
		else
		{
			drow_julia(img, img->c, img->magnification_rate);
		}
	}
	if (keycode == 5)
	{
		img->magnification_rate *= 1.1;
		if (img->is_mandelbrot == true)
			drow_mandelbrot(img, img->magnification_rate);
		else
		{
			drow_julia(img, img->c, img->magnification_rate);
		}
	}
	return (0);
}
