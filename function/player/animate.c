/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:08:28 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 17:55:23 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	action_on_finish(t_player *player, t_game *game)
{
	if (player->coin != game->map.coin)
	{
		player->life--;
		if (player->life < 0)
			exit_game(game);
		reset_game(game);
		return ;
	}
	if (player->level < game->map.levels)
	{
		player->level += 1;
		reset_game(game);
		return ;
	}
	else
		exit_game(game);
}

void	always_on_ground(t_game *game)
{
	t_player	*player;

	player = &game->map.player;
	if (!hit(game, *player) && player->jumping == 0)
	{
		player->falling = 1;
		player->y += STEP;
		if (hit(game, *player))
		{
			player->y -= STEP;
			player->falling = 0;
			player->previous_y = player->y;
			if (player->finished == 1)
				action_on_finish(player, game);
		}
	}
}

void	inertie_on_right(t_game *game, t_player *player)
{
	if (player->scrolling == 0)
	{
		player->x += STEP;
		if (hit(game, *player))
		{
			player->x -= STEP * 2;
			player->inertie = 0;
			player->delay = 1;
		}
	}
	else
	{
		player->chunk_cursor += move_chunk_right(game);
		if (hit(game, *player))
		{
			player->chunk_cursor -= move_chunk_left(game);
			player->inertie = 0;
			player->delay = 1;
		}
	}
}

void	apply_inertie(t_game *game)
{
	t_player	*player;

	player = &game->map.player;
	if (player->moving == 0 && player->inertie > 0)
	{
		if (game->time / player->delay != player->inertie_time)
		{
			if (player->dir == 1)
				inertie_on_right(game, player);
			else if (player->dir == -1 && player->x > 0)
			{
				player->x -= STEP;
				if (hit(game, *player))
				{
					player->x += STEP * 2;
					player->inertie = 0;
					player->delay = 1;
				}
			}
			player->inertie--;
			player->delay += 5;
		}
	}
}

void	die(t_game *game)
{
	if (game->map.player.die == 1)
	{
		game->map.player.step = 3;
		if (game->time / DIE_DELAY != game->map.player.die_time
			&& game->map.player.frame_to_die > 0)
		{
			if (game->map.player.frame_to_die <= FRAME_TO_DIE / 2)
				game->map.player.y++;
			else
				game->map.player.y--;
			game->map.player.frame_to_die--;
		}
		else if (game->map.player.frame_to_die == 0)
		{
			if (game->map.player.life > 0)
			{
				reset_game(game);
				game->map.player.life -= 1;
			}
			else
				exit_game(game);
		}
	}
}
