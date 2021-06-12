#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "so_long_struct.h"
#include "stdio.h"
#include <fcntl.h>

#ifndef SO_LONG
# define SO_LONG

/*
** DRAW
**
*/

void pixel_put(t_data *data, int x, int y, int color);
int draw_map(t_game *game);
char *get_color(char **addr, int width, int x, int y);
int draw_player(t_game *game);
int move_chunk_right(t_game *game);
int move_chunk_left(t_game *game);

/*
** SARRAY
**
*/

t_sarray new_sarray();
void push_sarray(char *new_line, t_sarray *array);
void print_sarray(t_sarray array);

/*
** PARSING
**
**/

t_sarray parse_map(char *path);
t_player get_spawn(t_sarray buffer);

/*
** HOOK EVENT
**
*/

void register_hook(t_game *game);
int close_window(int key, t_game *game);
int player_move(int key, t_game *game);
int key_press(t_game *game, int key);

/*
** RENDERING
**
*/

int rendering(t_game *game);

/*
** INIT
**
*/

t_game init_game();


/*
** INPUT
**
*/

int search_input(t_input input, int key);
void print_input(t_input input);
void add_input(t_input *input, int key);
void remove_input(t_input *input, int key);
void foreach_input(t_input input, t_game *game, int (*f)(t_game *, int));

#endif