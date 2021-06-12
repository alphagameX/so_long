
#ifndef SO_LONG_STRUCT
#define SO_LONG_STRUCT

#define to , &
#define HEIGHT 600
#define WIDTH 800
#define STEP 1
#define CHUNCK_SIZE 25

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

	int step_x;
	int step_y;
	t_texture *textures;
}				t_player;

typedef struct s_chunk {
	int size;
	int cursor;
	int step;
	int dir;
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