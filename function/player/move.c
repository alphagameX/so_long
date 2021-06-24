/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:01:37 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 11:26:57 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

int	special_hit (t_game *game, t_player player, t_hit i)
{
	if (game->map.buffer.buffer[i.y1][i.x1] == 'C')
	{
		game->map.buffer.buffer[i.y1][i.x1] = '0';
		game->map.player.coin++;
	}
	if (game->map.buffer.buffer[i.y1][i.x0] == 'C')
	{
		game->map.buffer.buffer[i.y1][i.x0] = '0';
		game->map.player.coin++;
	}
	if (game->map.buffer.buffer[i.y1][i.x0] == 'M')
	{
		game->map.player.finished = 1;
	}
	if (game->map.buffer.buffer[i.y1][i.x0] == '#' || game->map.buffer.buffer
		[i.y1][i.x1] == '#' || player.y >= (HEIGHT - (WIDTH
		/ CHUNCK_SIZE)) - STEP)
	{
		game->map.player.die = 1;
		return (1);
	}
	return (0);
}

void	changing_state(t_game *game, t_hit i)
{
	if (game->map.buffer.buffer[i.y1][i.x1] == 'C')
	{
		game->map.buffer.buffer[i.y1][i.x1] = '0';
		game->map.player.coin++;
	}
	if (game->map.buffer.buffer[i.y1][i.x0] == 'C')
	{
		game->map.buffer.buffer[i.y1][i.x0] = '0';
		game->map.player.coin++;
	}
	if (game->map.buffer.buffer[i.y1][i.x0] == 'M')
		game->map.player.finished = 1;
}

int	hit_die(t_player player, t_game *game, t_hit i)
{
	if (player.y >= (HEIGHT - (WIDTH / CHUNCK_SIZE)) - STEP)
	{
		game->map.player.die = 1;
		return (1);
	}
	if (game->map.buffer.buffer[i.y1][i.x0] == '#')
	{
		game->map.player.die = 1;
		return (1);
	}
	if (game->map.buffer.buffer[i.y1][i.x1] == '#')
	{
		game->map.player.die = 1;
		return (1);
	}
	return (0);
}

int 	hit(t_game *game, t_player player)
{
	t_hit	i;

	i = init_hit(game, player);
	if (_h(game->map.buffer.buffer[i.y0][i.x0]) ||
			_h(game->map.buffer.buffer[i.y0][i.x1]) ||
			_h(game->map.buffer.buffer[i.y1][i.x0]) ||
			_h(game->map.buffer.buffer[i.y1][i.x1]))
	{
		if ((_h(game->map.buffer.buffer[i.y0][i.x1]) && game->map.buffer.buffer
			[i.y1][i.x1] == '0') || (_h(game->map.buffer.buffer[i.y0][i.x0])
				&& game->map.buffer.buffer[i.y1][i.x0] == '0'))
		{
			if (_h(game->map.buffer.buffer[(player.y + STEP) / (HEIGHT
							/ CHUNCK_SIZE)][i.x1]) || _h(
							game->map.buffer.buffer[(player.y
							+ STEP) / (HEIGHT / CHUNCK_SIZE)][i.x0]))
				return (1);
			return (0);
		}
		return (1);
	}
	if (hit_die(player, game, i) == 1)
		return (1);
	changing_state(game, i);
	return (0);
}

int 	player_move(int key, t_game *game)
{
	t_player	*player;

	player = &game->map.player;
	if (player->die == 0 && player->finished == 0)
	{
		if (key == LEFT)
			left(player, game);
		if (key == RIGHT)
			right(player, game);
		if (key == UP)
			up(player, game);
	}
	return (1);
}
