#include "../libft/libft.h"
#include "so_long_struct.h"
#include "so_long_norm_struct.h"
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
void draw_hud(t_game *game);

/*
** SARRAY
**
*/

t_sarray new_sarray();
void push_sarray(char *new_line, t_sarray *array);
void print_sarray(t_sarray array);
void free_sarray(t_sarray *array);

/*
** PARSING
**
**/

t_sarray parse_map(t_game *game);
t_player get_spawn(t_sarray buffer);
void checking_map(t_sarray *array, t_game *game);
void interpret_map(t_sarray *array, t_game *game);

/*
** HOOK EVENT
**
*/

void register_hook(t_game *game);
int close_window(int key, t_game *game);
int key_press(t_game *game, int key);
int unregister_key(int key, t_game *game);


/*
** PLAYER
**
*/

void apply_inertie(t_game *game);
void die(t_game *game);
void always_on_ground(t_game *game);
int _h(char c);
int hit(t_game *game, t_player player);
int player_move(int key, t_game *game);

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
t_player init_player(t_game *game);
void conf(t_game *game);
void set_player_conf(t_game *game, t_player *player);
void set_chunk_conf(t_chunk *chunk);
void how_many_level(t_game *game);
t_texture *load_texture(t_game *game, char **paths, int count);

/*
** INPUT
**
*/

int search_input(t_input input, int key);
void print_input(t_input input);
void add_input(t_input *input, int key);
void remove_input(t_input *input, int key);
void foreach_input(t_input input, t_game *game, int (*f)(t_game *, int));

/*
** EXIT
**
*/

void exit_game(t_game *game);
void reset_game(t_game *game);

/*
** NORM
**
*/

t_checking_map init_checking_map();


#endif