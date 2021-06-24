/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:25:12 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:25:13 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	conf(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->image.img = NULL;
	game->textures = NULL;
	game->map.player.textures = NULL;
	game->map.player.level = 1;
	game->map.levels = 0;
	game->time = 0;
	how_many_level(game);
	set_chunk_conf(&game->map.chunk);
	game->map.player = init_player(game);
	game->input.count = 0;
	game->input.list = NULL;
}

void	set_player_conf(t_game *game, t_player *player)
{
	player->x = (WIDTH / CHUNCK_SIZE) * (player->spawn_x - 1);
	player->y = (HEIGHT - ((WIDTH / CHUNCK_SIZE) * (game->map.buffer.count
					- player->spawn_y))) - 1;
	player->jumping = 0;
	player->falling = 0;
	player->previous_y = player->y;
	player->dir = 0;
	player->delay = 1;
	player->moving = 0;
	player->step = 0;
	player->die = 0;
	player->frame_to_die = 120;
	player->chunk_cursor = 0;
	player->step_time = 0;
	player->coin = 0;
	player->finished = 0;
	player->move = 0;
}

void	set_chunk_conf(t_chunk *chunk)
{
	chunk->cursor = 1;
	chunk->size = CHUNCK_SIZE;
	chunk->step = 0;
	chunk->count = 0;
}
