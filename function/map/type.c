/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:06:42 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 13:06:43 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

int	get_block_type_1(t_map map, int x, int y)
{
	if (map.buffer.buffer[y][x] == 'C')
		return (3);
	if (map.buffer.buffer[y][x] == 'G')
		return (0);
	if (y == 0 || map.buffer.buffer[y][x] == 'V')
		return (-1);
	if (map.buffer.buffer[y][x] == 'B')
		return (1);
	if (map.buffer.buffer[y][x] == 'M')
		return (4);
	if (map.buffer.buffer[y][x] == 'W')
		return (5);
	if (map.buffer.buffer[y][x] == 'U')
		return (6);
	return (-2);
}

int	get_block_type_2(t_map map, int x, int y)
{
	if (map.buffer.buffer[y][x] == 'T')
		return (8);
	if (map.buffer.buffer[y][x] == 'I')
		return (7);
	if (map.buffer.buffer[y][x] == '2')
		return (9);
	if (map.buffer.buffer[y][x] == '3')
		return (10);
	if (map.buffer.buffer[y][x] == '4')
		return (11);
	if (map.buffer.buffer[y][x] == '5')
		return (12);
	if (map.buffer.buffer[y][x] == '#')
		return (13);
	return (-2);
}

int	get_block_type(t_map map, int x, int y)
{	
	int	ret;

	ret = get_block_type_1(map, x, y);
	if (ret != -2)
		return (ret);
	ret = get_block_type_2(map, x, y);
	if (ret != -2)
		return (ret);
	return (2);
}
