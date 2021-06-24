/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:14:30 by arthur            #+#    #+#             */
/*   Updated: 2021/06/23 23:20:43 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	right_chunk(t_player *player, t_game *game)
{
	int	move;

	player->scrolling = 1;
	move = move_chunk_right(game);
	player->chunk_cursor += move;
	player->move += move;
	if (hit(game, *player))
	{
		player->chunk_cursor -= move_chunk_left(game);
		player->moving = 0;
	}
}

void	right(t_player *player, t_game *game)
{
	player->moving = 1;
	player->dir = 1;
	if (player->x < WIDTH / 2 || !(game->map.chunk.cursor <= ((ft_strlen(
						game->map.buffer.buffer[0]) - 1) - CHUNCK_SIZE) - 1))
	{
		player->scrolling = 0;
		player->x += STEP;
		if (player->x % (WIDTH / CHUNCK_SIZE) == 0)
			player->move++;
		if (hit(game, *player))
		{
			player->x -= STEP;
			player->moving = 0;
		}
	}
	else
		right_chunk(player, game);
}

void	left(t_player *player, t_game *game)
{
	player->moving = 1;
	player->dir = -1;
	if (player->x >= 0)
	{
		player->x -= STEP;
		if (player->x % (WIDTH / CHUNCK_SIZE) == 0)
			player->move++;
		if (hit(game, *player))
		{
			player->x += STEP;
			player->moving = 0;
		}
	}
}

void	up(t_player *player, t_game *game)
{
	if (player->falling == 0)
	{
		if (player->y > player->previous_y - ((WIDTH / CHUNCK_SIZE) * 4))
		{
			player->y -= STEP;
			player->jumping = 1;
			if (hit(game, *player))
			{
				player->y += STEP;
				unregister_key(UP, game);
			}
		}
		else
			unregister_key(UP, game);
	}
}
