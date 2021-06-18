#include "../source/so_long.h"


int rendering(t_game *game)
{


    game->time += 1;

    foreach_input(game->input, game, key_press);

    mlx_destroy_image(game->mlx, game->image.img);
	game->image.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bits_per_pixel, &game->image.line_length, &game->image.endian);


    draw_map(game);
    draw_player(game);


	mlx_put_image_to_window(game->mlx, game->window, game->image.img, 0, 0);


    // print_blocks(*game);


   
	// exit(1);
 
    game->map.player.inertie_time = game->time / game->map.player.delay;
    game->map.player.step_time = game->time / STEP_TIME;

    return (1);

}