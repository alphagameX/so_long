#include "../../source/so_long.h"

t_player init_player(t_game *game)
{

    t_player player;
  
    game->map.buffer = parse_map(game);
    checking_map(&game->map.buffer, game);
    interpret_map(&game->map.buffer, game);
    player = get_spawn(game->map.buffer);
    set_player_conf(game, &player);
    player.life = 3;
    player.level = game->map.player.level;
    return (player);
}

void *mlx_setup(t_game *game)
{
    void *mlx;
    mlx = mlx_init();

    game->window = mlx_new_window(mlx, WIDTH, HEIGHT, "So long");
    game->image.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bits_per_pixel, &game->image.line_length, &game->image.endian);
    mlx_put_image_to_window(mlx, game->window, game->image.img, 0, 0);

    mlx_do_key_autorepeatoff(mlx);

    return (mlx);
}

t_game init_game()
{
    t_game new;
    static char *textures[14] = {
        "sprites/xpm/floor.xpm",
        "sprites/xpm/block.xpm",
        "sprites/xpm/stairs.xpm",
        "sprites/xpm/coin.xpm",
        "sprites/xpm/flag_1.xpm",
        "sprites/xpm/flag_2.xpm",
        "sprites/xpm/flag_3.xpm",
        "sprites/xpm/flag_4.xpm",
        "sprites/xpm/flag_5.xpm",
        "sprites/xpm/pipe_top_left.xpm",
        "sprites/xpm/pipe_top_right.xpm",
        "sprites/xpm/pipe_middle_left.xpm",
        "sprites/xpm/pipe_middle_right.xpm",
        "sprites/xpm/enemy_1.xpm"
    };
    static char *sprites[6] = {
        "sprites/xpm/player_1.xpm",
        "sprites/xpm/player_jump.xpm",
        "sprites/xpm/player_step_1.xpm",
        "sprites/xpm/player_step_2.xpm",
        "sprites/xpm/player_step_3.xpm",
        "sprites/xpm/player_die.xpm"
    };

    conf(&new);

    new.mlx = mlx_setup(&new);
    new.map.player.textures = load_texture(&new, sprites, 6);
    new.textures = load_texture(&new, textures, 14);

    return (new);
}
