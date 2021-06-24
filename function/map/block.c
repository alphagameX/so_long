/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:29:25 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:07:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	draw_first_block(t_game *game, t_draw_block i)
{
	char	*color;
	int		drawX;

	drawX = i.x + i.width;
	if ((drawX - i.xi) >= 0 && (drawX - i.xi) <= WIDTH && (i.y + i.yi) >= 0
		&& (i.y + i.yi) <= HEIGHT)
	{
		if (i.type != -1)
		{
			color = get_color(&game->textures[i.type].img.addr,
					game->textures[i.type].width, i.yi / 2,
					((WIDTH / CHUNCK_SIZE) - i.xi) / 2);
			pixel_put(&game->image, drawX - i.xi, i.y + i.yi,
				*(unsigned int *)color);
		}
		else
			pixel_put(&game->image, drawX - i.xi, i.y + i.yi, 0xa1aeff);
	}
}

void	draw_regular_block(t_game *game, t_draw_block i)
{
	char	*color;

	if (i.x + i.xi <= WIDTH && i.y + i.yi <= HEIGHT && i.x + i.xi
		>= 0 && i.y + i.yi >= 0)
	{
		if (i.type != -1)
		{
			color = get_color(&game->textures[i.type].img.addr,
					game->textures[i.type].width, i.yi / 2,
					i.xi / 2);
			pixel_put(&game->image, i.x + i.xi, i.y + i.yi,
				*(unsigned int *)color);
		}
		else
		{
			pixel_put(&game->image, i.x + i.xi, i.y + i.yi, 0xa1aeff);
		}
	}
}

void	draw_block(t_game *game, t_draw_block i)
{
	i.xi = 0;
	while (i.xi < i.width)
	{
		i.yi = 0;
		while (i.yi < i.height)
		{
			if (i.x / (WIDTH / CHUNCK_SIZE) == 0 )
				draw_first_block(game, i);
			else
				draw_regular_block(game, i);
			i.yi++;
		}
		i.xi++;
	}	
}

void	draw_last_block(t_game *game, int x, int block)
{
	int				y;
	t_draw_block	i;

	y = 0;
	while (y < game->map.buffer.count)
	{
		i.type = -1;
		i.height = block;
		i.width = game->map.chunk.step;
		i.y = HEIGHT - (block * (y + 1));
		i.x = (x + block) - game->map.chunk.step;
		if (_h(game->map.buffer.buffer[(game->map.buffer.count - 1) - y]
				[(game->map.chunk.cursor + (x / block)) + 1]))
		{
			i.type = get_block_type(game->map, (game->map.chunk.cursor
						+ (x / block)) + 1, (game->map.buffer.count - 1) - y);
			draw_block(game, i);
		}
		else
			draw_block(game, i);
		y += 1;
	}
}
