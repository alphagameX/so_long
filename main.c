

#include "source/so_long.h"


int main (void) {

    t_game game;

    game = init_game();

    register_hook(&game);

    mlx_loop(game.mlx);

    return (0);

}