/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:46:46 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 17:54:54 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	rendering(t_game *game)
{
	game->time += 1;
	game->map.player.previous_move = game->map.player.move;
	foreach_input(game->input, game, key_press);
	mlx_destroy_image(game->mlx, game->image.img);
	game->image.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->image.addr = mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel,
			&game->image.line_length, &game->image.endian);
	draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image.img, 0, 0);
	draw_hud(game);
	game->map.player.inertie_time = game->time / game->map.player.delay;
	game->map.player.step_time = game->time / STEP_TIME;
	game->map.player.die_time = game->time / DIE_DELAY;
	return (1);
}
