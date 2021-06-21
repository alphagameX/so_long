#include "../source/so_long.h"


int close_window(int key, t_game *game)
{
    if(key == ECHAP)
    {
        mlx_do_key_autorepeaton(game->mlx);
        exit_game(game);
    }
    return (1);
}

