#include "../source/so_long.h"


t_texture *load_texture(t_game *game, char **paths, int count)
{
    t_texture *textures;
    int i;

    i = 0;
    textures = malloc(sizeof(t_texture) * (count + 1));
    if(!textures)
        exit(2);
    while(i < count)
    {
        textures[i].path = ft_strdup(paths[i]);
        textures[i].img.img = mlx_xpm_file_to_image(game->mlx, paths[i], &textures[i].width, &textures[i].height);
        textures[i].img.addr = mlx_get_data_addr(textures[i].img.img, &textures[i].img.bits_per_pixel, &textures[i].img.line_length, &textures[i].img.endian);
        i++;
    }
    textures[i].path = NULL;

    return textures;
}

t_player init_player(t_game *game)
{
    t_player player;
    static char *sprites[5] = {
        "sprites/xpm/player_1.xpm",
        "sprites/xpm/player_jump.xpm",
        "sprites/xpm/player_step_1.xpm",
        "sprites/xpm/player_step_2.xpm",
        "sprites/xpm/player_step_3.xpm"
    };

    game->map.buffer = parse_map("map.ber");
    player = get_spawn(game->map.buffer);
    checking_map(&game->map.buffer, game);
    interpret_map(&game->map.buffer, game);
    player.x = (WIDTH / CHUNCK_SIZE) * (player.spawn_x - 1);
    player.y = (HEIGHT - ((WIDTH / CHUNCK_SIZE) * (game->map.buffer.count - player.spawn_y))) - 1;
    player.jumping = 0;
    player.falling = 0;
    player.previous_y = player.y;
    player.dir = 0;
    player.delay = 1;
    player.step = 0;
    player.chunk_cursor = 0;
    player.textures = load_texture(game, sprites, 5);

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
    static char *textures[3] = {
        "sprites/xpm/block.xpm",
        "sprites/xpm/floor.xpm",
        "sprites/xpm/stairs.xpm"
    };

    new.mlx = mlx_setup(&new);
    new.textures = NULL;
    new.map.player.textures = NULL;

    new.map.player = init_player(&new);
    new.map.chunk.cursor = 1;
    new.map.chunk.size = CHUNCK_SIZE;
    new.map.chunk.step = 0;
    new.map.chunk.count = 0;
    new.input.count = 0;
    new.input.list = NULL;
   
    new.textures = load_texture(&new, textures, 3);


    return (new);
}
