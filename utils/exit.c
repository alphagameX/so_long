#include "../source/so_long.h"

void exit_game(t_game *game)
{
    int i;
    int y;

    i = 0;
    if(game->textures)
    {
        while(game->textures[i].path != NULL)
        {
            free(game->textures[i].path);
            mlx_destroy_image(game->mlx, game->textures[i].img.img);
            i++;
        }
    }

    i = 0;
    if(game->map.player.textures)
    {   
        while(game->map.player.textures[i].path != NULL)
        {
            free(game->map.player.textures[i].path);
            mlx_destroy_image(game->mlx, game->map.player.textures[i].img.img);
            i++;
        }
    }

    i = 0;

    while(i < game->map.buffer.count)
    {
        free(game->map.buffer.buffer[i]);
        i++;
    }
    exit(0);
}