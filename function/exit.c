/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:33:49 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:38:23 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

void	reset_game(t_game *game)
{
	free_sarray(&game->map.buffer);
	game->map.buffer = parse_map(game);
	checking_map(&game->map.buffer, game);
	interpret_map(&game->map.buffer, game);
	set_player_conf(game, &game->map.player);
	set_chunk_conf(&game->map.chunk);
}

void	free_textures_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->textures)
	{
		while (game->textures[i].path != NULL)
		{
			free(game->textures[i].path);
			mlx_destroy_image(game->mlx, game->textures[i].img.img);
			i++;
		}
		free(game->textures);
	}
}

void	free_textures_player(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.player.textures)
	{
		while (game->map.player.textures[i].path != NULL)
		{
			free(game->map.player.textures[i].path);
			mlx_destroy_image(game->mlx, game->map.player.textures[i].img.img);
			i++;
		}
		free(game->map.player.textures);
	}
}

void	exit_game(t_game *game)
{
	free_textures_map(game);
	free_textures_player(game);
	if (game->input.count > 0)
		free(game->input.list);
	free_sarray(&game->map.buffer);
	if (game->image.img)
		mlx_destroy_image(game->mlx, game->image.img);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
