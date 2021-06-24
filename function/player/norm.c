/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:28:21 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 11:06:24 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

t_hit	init_hit(t_game *game, t_player player)
{
	t_hit	i;

	if (game->map.chunk.step > 0)
		player.x += game->map.chunk.step;
	i.x0 = (((player.x + STEP) / (WIDTH / CHUNCK_SIZE)) + 1);
	i.x1 = (((player.x + ((WIDTH / CHUNCK_SIZE) - STEP))
				/ (WIDTH / CHUNCK_SIZE)) + 1);
	i.y0 = (player.y / (HEIGHT / CHUNCK_SIZE));
	i.y1 = (player.y + (HEIGHT / CHUNCK_SIZE)) / (HEIGHT / CHUNCK_SIZE);
	i.x0 += player.chunk_cursor;
	i.x1 += player.chunk_cursor;
	return (i);
}

int	_h(char c)
{
	if (c == '1' || c == 'G' || c == 'B' || c == '2' || c == '3' || c
		== '4' || c == '5')
		return (1);
	return (0);
}
