/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:37:19 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 11:41:27 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

void	has_good_extension(t_game *game, char *path)
{
	if (ft_strnstr(path, ".ber", ft_strlen(path)) == NULL)
	{
		ft_putstr("Error\n");
		ft_putstr("Map file is not .ber\n");
		free(path);
		exit_game(game);
	}
}

int	file_exists(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		ft_putstr("Invalid map path\n");
		free(path);
		exit_game(game);
	}
	return (fd);
}

t_sarray	parse_map(t_game *game)
{
	int			fd;
	int			ret;
	char		*line;
	t_sarray	array;
	char		*path;

	path = NULL;
	line = ft_itoa(game->map.player.level);
	ft_argv_strjoin(&path, 3, "level/level_", line, ".ber");
	free(line);
	has_good_extension(game, path);
	array = new_sarray();
	fd = file_exists(game, path);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		push_sarray(line to array);
	}
	free(path);
	return (array);
}

t_player 	get_spawn(t_sarray array)
{
	int			x;
	int			y;
	t_player	player;

	y = 0;
	while (y < array.count)
	{
		x = 0;
		while (array.buffer[y][x])
		{
			if (array.buffer[y][x] == 'P')
			{
				player.spawn_x = x;
				player.spawn_y = y;
				return (player);
			}
			x++;
		}
		y++;
	}
	exit(0);
}
