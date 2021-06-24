/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:42:05 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:42:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	draw_life (t_game *game)
{
	char	*life;
	char	*tmp;

	tmp = ft_itoa(game->map.player.life);
	life = ft_strjoin(tmp, "/3");
	mlx_string_put(game->mlx, game->window, 10, 20, 0x000000, life);
	free(tmp);
	free(life);
}

void	draw_level(t_game *game)
{
	char	*level;
	char	*tmp_1;
	char	*tmp_2;

	tmp_1 = ft_itoa(game->map.player.level);
	tmp_2 = ft_itoa(game->map.levels);
	level = NULL;
	ft_argv_strjoin(&level, 3, tmp_1, "-", tmp_2);
	mlx_string_put(game->mlx, game->window, 10, 60, 0x000000, level);
	free(tmp_1);
	free(tmp_2);
	free(level);
}

void	draw_coin(t_game *game)
{
	char	*coin;
	char	*tmp_1;
	char	*tmp_2;

	coin = NULL;
	tmp_1 = ft_itoa(game->map.player.coin);
	tmp_2 = ft_itoa(game->map.coin);
	ft_argv_strjoin(&coin, 3, tmp_1, "/", tmp_2);
	mlx_string_put(game->mlx, game->window, 10, 40, 0x000000, coin);
	free(tmp_1);
	free(tmp_2);
	free(coin);
}

void	draw_move(t_game *game)
{
	char	*move;
	char	*tmp_1;
	char	*tmp_2;

	tmp_1 = ft_itoa(game->map.player.move);
	tmp_2 = ft_itoa(ft_strlen(game->map.buffer.buffer[0]) - CHUNCK_SIZE);
	move = NULL;
	ft_argv_strjoin(&move, 3, tmp_1, " moves / best ~ ", tmp_2);
	mlx_string_put(game->mlx, game->window, 10, 80, 0x00000, move);
	if (game->map.player.move != game->map.player.previous_move)
		ft_printf("%d\n", game->map.player.move);
	free(tmp_1);
	free(tmp_2);
	free(move);
}

void	draw_hud(t_game *game)
{
	draw_life(game);
	draw_level(game);
	draw_coin(game);
	draw_move(game);
}
