#include "../source/so_long.h"


void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

char	*get_color(char **addr, int width, int x, int y)
{
	return (*addr + (4 * width * x) + (4 * y));
}
