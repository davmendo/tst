#include "fractol.h"

void	init_data(t_data *data)
{
	data->zoom = 200.0;
	data->offset_x = WIN_WIDTH / 2.0;
	data->offset_y = WIN_HEIGHT / 2.0;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->img_addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	compute_mandelbrot(double x0, double y0, int max_iter)
{
	double	x;
	double	y;
	double	xtemp;
	int		iter;

	x = 0.0;
	y = 0.0;
	iter = 0;
	while (x * x + y * y <= 4.0 && iter < max_iter)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		iter++;
	}
	return (iter);
}

int	compute_julia(double x0, double y0, t_complex c, int max_iter)
{
	double	x;
	double	y;
	double	xtemp;
	int		iter;

	x = x0;
	y = y0;
	iter = 0;
	while (x * x + y * y <= 4.0 && iter < max_iter)
	{
		xtemp = x * x - y * y + c.re;
		y = 2 * x * y + c.im;
		x = xtemp;
		iter++;
	}
	return (iter);
}
