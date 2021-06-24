/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:41:53 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:19:54 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

t_draw_block	init_draw_block(t_game *game, int x, int y, char *c)
{
	t_draw_block	i;

	*c = game->map.buffer.buffer[(game->map.buffer.count - 1) - y]
	[game->map.chunk.cursor + (x / (WIDTH / CHUNCK_SIZE))];
	i.height = (WIDTH / CHUNCK_SIZE);
	i.y = HEIGHT - ((WIDTH / CHUNCK_SIZE) * (y + 1));
	i.x = x - game->map.chunk.step;
	i.width = WIDTH / CHUNCK_SIZE;
	return (i);
}

void	on_screen(t_game *game, int x, int y)
{
	char			c;
	t_draw_block	i;

	i = init_draw_block(game, x, y, &c);
	if (_h(c) || c == 'C' || c == 'M' || c == 'T' || c == 'I'
		|| c == 'U' || c == 'W' || c == '#')
	{
		i.type = get_block_type(game->map, game->map.chunk.cursor
				+ (x / (WIDTH / CHUNCK_SIZE)),
				(game->map.buffer.count - 1) - y);
		if (x / (WIDTH / CHUNCK_SIZE) == 0)
		{
			i.width = (WIDTH / CHUNCK_SIZE) - game->map.chunk.step;
			i.x = x;
			draw_block(game, i);
		}
		else
			draw_block(game, i);
	}
	else
	{
		i.type = -1;
		draw_block(game, i);
	}
}

int	draw_map(t_game *game)
{
	int	block;
	int	x;
	int	y;

	x = 0;
	block = (WIDTH / CHUNCK_SIZE);
	while (x < WIDTH)
	{
		y = 0;
		while (y < game->map.buffer.count)
		{
			on_screen(game, x, y);
			y++;
		}
		if (block * CHUNCK_SIZE == WIDTH)
		{
			if (x / block == CHUNCK_SIZE - 1 && game->map.chunk.step > 0)
				draw_last_block(game, x, block);
		}
		x += block;
	}
	return (1);
}
