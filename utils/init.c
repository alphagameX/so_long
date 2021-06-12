#include "../source/so_long.h"


t_texture *load_texture(t_game *game, char **paths, int count)
{
    t_texture *textures;
    int i;

    i = 0;
    textures = malloc(sizeof(t_texture) * count + 1);
    if(!textures)
        exit(1);
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

t_game init_game()
{
    t_game new;
    static char *textures[3] = {
        "sprites/xpm/block.xpm",
        "sprites/xpm/floor.xpm",
        "sprites/xpm/stairs.xpm"
    };
    static char *sprites[1] = {
        "sprites/xpm/player_1.xpm"
    };

    new.mlx = mlx_init();

    new.map.buffer = parse_map("map.ber");
    new.map.player = get_spawn(new.map.buffer);

    new.map.chunk.cursor = 1;
    new.map.chunk.size = CHUNCK_SIZE;
    new.map.chunk.step = 0;
    new.map.chunk.dir = 1;
    new.input.count = 0;
    new.input.list = NULL;

    new.window = mlx_new_window(new.mlx, WIDTH, HEIGHT, "So long");
    new.image.img = mlx_new_image(new.mlx, WIDTH, HEIGHT);
    new.image.addr = mlx_get_data_addr(new.image.img, &new.image.bits_per_pixel, &new.image.line_length, &new.image.endian);
    mlx_put_image_to_window(new.mlx, new.window, new.image.img, 0, 0);

    new.textures = load_texture(&new, textures, 3);
    new.map.player.textures = load_texture(&new, sprites, 1);

    printf("%s\n", new.textures[0].path);

    return (new);
}
