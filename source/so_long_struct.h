/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:05:49 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 15:05:50 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_STRUCT
#define SO_LONG_STRUCT

#define to , &
#define HEIGHT 800
#define WIDTH 800
#define STEP 1
#define CHUNCK_SIZE 25
#define STEP_TIME 100

#if OS == 1
#include "../mlx_linux/mlx.h"

#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define ECHAP 65307

#else
#include "../mlx_osx/mlx.h"

#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define ECHAP 53

#endif


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_sarray {
    char **buffer;
    int count;
}               t_sarray;

typedef struct s_texture {
	char *path;
	int width;
	int height;
	t_data img;
}				t_texture;

typedef struct s_player {
	int x;
	int y;
	int spawn_x;
	int spawn_y;
	int jumping;
	int falling;
	int previous_y;
	int moving;
	int inertie;
	int dir;
	int delay;
	int step;
	int inertie_time;
	int step_time;
	int scrolling;
	int chunk_cursor;
	int die;
	int die_time;
	int frame_to_die;
	int life;
	int coin;
	int finished;
	int level;
	int move;
	int previous_move;
	t_texture *textures;
}				t_player;

typedef struct s_chunk {
	int size;
	int cursor;
	int step;
	int count;
}				t_chunk;

typedef struct s_map {
	t_sarray buffer;
	t_player player;
	t_chunk chunk;

	int coin;
	int levels;
} 				t_map;

typedef struct s_input {
	int *list;
	int count;
}				t_input;

typedef struct s_coord {
	int y;
	int x;
	int type;
}	t_coord;

typedef struct s_game {
	t_map map;
	t_data image;
	t_texture *textures;
	t_input input;

	int old_time;
	int time;

	void *mlx;
	void *window;

} 			t_game;

#endif