#include "../source/so_long.h"

int key_press(t_game *game, int key)
{
    // print_input(game->input);
    close_window(key, game);
    player_move(key, game);
    return (1);
}

int register_key(int key, t_game *game)
{
    
    if(!search_input(game->input, key))
        add_input(&game->input, key);

    return (1);
}

int unregister_key(int key, t_game *game)
{
    //printf("release: %d\n", key);

    if(search_input(game->input, key))
        remove_input(&game->input, key);

    return (1);
}

void register_hook(t_game *game)
{
    mlx_hook(game->window, 02, (1L << 0), register_key, game);
    mlx_hook(game->window, 03, (1L << 1), unregister_key, game);
    mlx_loop_hook(game->mlx, rendering, game);
}