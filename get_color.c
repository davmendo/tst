#include "fractol.h"

int	get_color(int iter)
{
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	r = (iter * 9) % 256;
	g = (iter * 7) % 256;
	b = (iter * 3) % 256;
	return (r * 65536 + g * 256 + b);
}
