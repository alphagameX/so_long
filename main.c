/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:49:35 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:49:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/so_long.h"

int	main (void)
{
	t_game	game;

	game = init_game();
	register_hook(&game);
	mlx_loop(game.mlx);
	return (0);
}
