
#ifndef SO_LONG_STRUCT
#define SO_LONG_STRUCT

#define to , &
#define HEIGHT 800
#define WIDTH 800
#define STEP 1
#define CHUNCK_SIZE 25
#define STEP_TIME 50

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

	t_coord ***blocks;


	int old_time;
	int time;

	void *mlx;
	void *window;

} 			t_game;

#endif