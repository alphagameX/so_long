/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_norm_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:05:52 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 17:24:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_NORM_STRUCT_H
# define SO_LONG_NORM_STRUCT_H

typedef struct s_checking_map
{
	int			y;
	int			x;
	int			c;
	int			p;
	int			e;
}				t_checking_map;

typedef struct s_hit
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_hit;

typedef struct s_draw_block
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			type;
	int			yi;
	int			xi;
}				t_draw_block;

/*
** NORM
**
*/

t_checking_map	init_checking_map(void);
t_hit			init_hit(t_game *game, t_player player);
int				_h(char c);

#endif