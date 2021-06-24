/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:46:42 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:46:43 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	close_window(int key, t_game *game)
{
	if (key == ECHAP)
	{
		mlx_do_key_autorepeaton(game->mlx);
		exit_game(game);
	}
	return (1);
}
