#include "../../source/so_long.h"

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
    return (textures);
}

void how_many_level(t_game *game)
{
    int i;
    char *path;
    char *level;
    int fd;

    path = NULL;

    fd = 0;
    i = 1;
    while(fd != -1)
    {
        if(path != NULL)
        {
            free(path);
            path = NULL;
        }
        level = ft_itoa(i);
        ft_argv_strjoin(&path, 3, "level/level_", level,".ber");
        free(level);
        fd = open(path, O_RDONLY);
        if(fd != -1)
            game->map.levels++;
        i++;
    }
    free(path);
}