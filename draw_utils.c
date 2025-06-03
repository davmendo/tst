#include "fractol.h"

void	draw_fractal(t_data *data)
{
	pthread_t		threads[THREAD_COUNT];
	t_thread_args	args[THREAD_COUNT];
	int				i;
	int				slice_height;

	slice_height = WIN_HEIGHT / THREAD_COUNT;
	i = 0;
	while (i < THREAD_COUNT)
	{
		args[i].data = data;
		args[i].y_start = i * slice_height;
		if (i == THREAD_COUNT - 1)
			args[i].y_end = WIN_HEIGHT;
		else
			args[i].y_end = (i + 1) * slice_height;
		pthread_create(&threads[i], NULL, thread_draw, &args[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

static void	draw_pixel(t_data *data, int x, int y)
{
	double	xr;
	double	yi;
	int		iter;

	xr = (x - data->offset_x) / data->zoom;
	yi = (y - data->offset_y) / data->zoom;
	if (data->type == FRACT_MANDELBROT)
		iter = compute_mandelbrot(xr, yi);
	else
		iter = compute_julia(xr, yi, data->julia_c);
	put_pixel(data, x, y, get_color(iter));
}

static void	draw_row(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_pixel(data, x, y);
		x++;
	}
}

void	*thread_draw(void *arg)
{
	t_thread_args	*targ;
	int				y;

	targ = (t_thread_args *)arg;
	y = targ->y_start;
	while (y < targ->y_end)
	{
		draw_row(targ->data, y);
		y++;
	}
	return (NULL);
}
