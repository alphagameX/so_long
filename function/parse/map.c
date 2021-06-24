/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:30:01 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 11:30:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	create_flag(t_sarray *array, int y, int x)
{
	int	i;

	i = 1;
	array->buffer[y][x] = '1';
	while (i <= 7)
	{
		array->buffer[y - i][x] = 'M';
		i++;
	}
	array->buffer[y - i][x] = 'W';
	array->buffer[y - (i + 1)][x] = 'U';
	array->buffer[y - (i + 2)][x] = 'T';
	array->buffer[y - (i + 1)][x - 1] = 'I';
}

void 	create_pipe(t_sarray *array, t_game *game, int y, int x)
{
	int	yi;

	(void)game;
	if (x + 2 < ft_strlen(array->buffer[y]) && array->buffer[y][x + 1] == '1'
		&& array->buffer[y - 1][x] == '0' && array->buffer[y][x - 1] == '0'
		&& array->buffer[y - 1][x + 1] == '0' && array->buffer[y][x + 2] == '0'
		&& array->buffer[y + 1][x] == '1' && array->buffer[y + 1][x + 1] == '1'
		&& array->buffer[y + 1][x - 1] == '0' && array->buffer[y + 1]
		[x + 2] == '0')
	{
		yi = 1;
		array->buffer[y][x] = '2';
		array->buffer[y][x + 1] = '3';
		while (array->buffer[y + yi][x - 1] != '1' && array->buffer[y + yi]
			[x - 1] != 'G')
		{
			array->buffer[y + yi][x] = '4';
			array->buffer[y + yi][x + 1] = '5';
			yi++;
		}
	}
}

void 	create_ground_void (t_sarray *array, int y, int x)
{
	if (array->buffer[y][x] == '1')
		array->buffer[y][x] = 'G';
	if (array->buffer[y][x] == '0')
	{
		array->buffer[y][x] = 'V';
		array->buffer[y + 1][x] = 'V';
	}
}

void	inside_map(t_game *game, t_sarray *array, int y, int x)
{
	(void)game;
	if (array->buffer[y][x] == '1')
	{
		if (array->buffer[y + 1][x] == '0' && array->buffer[y - 1][x] == '0')
		{
			array->buffer[y][x] = 'B';
		}
		create_pipe(array, game, y, x);
	}
	if (array->buffer[y][x] == 'E')
	{
		if (y >= 10 && x > 2)
			create_flag(array, y, x);
		else
		{
			ft_putstr("Error\n");
			ft_putstr("Mario's flag end canno't be set\n");
			exit_game(game);
		}
	}
}

void	interpret_map(t_sarray *array, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	(void)game;
	while (y < array->count)
	{
		x = 0;
		while (x < ft_strlen(array->buffer[y]))
		{
			if (y + 1 < array->count - 1 && y > 0)
				inside_map(game, array, y, x);
			else if (y > array->count - 3)
			{
				create_ground_void(array, y, x);
			}
			x++;
		}
		y++;
	}
}
