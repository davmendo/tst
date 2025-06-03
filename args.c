#include "fractol.h"

static int	is_valid_float(const char *s)
{
	int		i;
	int		dot_count;

	if (!s || !s[0])
		return (0);
	i = 0;
	dot_count = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
			if (s[i + 1] == '\0')
				return (0);
		}
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(const char *s)
{
	double	res;
	double	sign;
	double	frac;
	double	div;

	res = 0.0;
	sign = 1.0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1.0;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10.0 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		frac = 0.0;
		div = 1.0;
		while (*s >= '0' && *s <= '9')
		{
			frac = frac * 10.0 + (*s++ - '0');
			div *= 10.0;
		}
		res += frac / div;
	}
	return (res * sign);
}

static void	init_data(t_data *data)
{
	data->zoom = 200.0;
	data->offset_x = WIN_WIDTH / 2.0;
	data->offset_y = WIN_HEIGHT / 2.0;
}

int	parse_args(int argc, char **argv, t_data *data)
{
	init_data(data);
	if (argc < 2)
		print_usage();
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		if (argc != 2)
			print_usage();
		data->type = FRACT_MANDELBROT;
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
			print_usage();
		if (!is_valid_float(argv[2]))
			print_usage();
		data->julia_c.re = ft_atof(argv[2]);
		if (!is_valid_float(argv[3]))
			print_usage();
		data->julia_c.im = ft_atof(argv[3]);
		data->type = FRACT_JULIA;
	}
	else
		print_usage();
	return (0);
}
