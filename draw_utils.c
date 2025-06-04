#include "fractol.h"

void	draw_line(t_data *data, int y)
{
	int		x;
	double	xr;
	double	yi;
	int		iter;

	x = 0;
	while (x < WIN_WIDTH)
	{
		xr = (x - data->offset_x) * data->inv_zoom;
		yi = (y - data->offset_y) * data->inv_zoom;
		if (data->type == FRACT_MANDELBROT)
			iter = compute_mandelbrot(xr, yi, data->max_iter);
		else
			iter = compute_julia(xr, yi, data->julia_c, data->max_iter);
		put_pixel(data, x, y, get_color(iter));
		x++;
	}
}

void	draw_fractal(t_data *data)
{
	int		y;
	int		base_iter;

	base_iter = 50;
	data->max_iter = base_iter + (int)(log2(data->zoom) * 10);
	if (data->max_iter > MAX_ITER)
		data->max_iter = MAX_ITER;
	if (data->max_iter < base_iter)
		data->max_iter = base_iter;
	data->inv_zoom = 1.0 / data->zoom;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		draw_line(data, y);
		y++;
	}
}
