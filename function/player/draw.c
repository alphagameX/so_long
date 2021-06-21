#include "../../source/so_long.h"


int get_sprite(t_game *game)
{
    int type;

    if(game->map.player.jumping == 1)
        type = 1;
    else
        type = 0;

    if(game->map.player.moving == 1 && game->map.player.jumping == 0 && game->map.player.falling == 0)
    {
        if(game->map.player.step == 0)
            type = 2;
        else if(game->map.player.step == 1)
            type = 3;
        else if(game->map.player.step == 2)
            type = 4;
    }

    if(game->map.player.die == 1)
        type = 5;

    return (type);
}

void draw_player_at(t_game *game, int x, int y)
{
    int xi;
    int yi;
    char *color;
    int type;

    xi = 0;
    type = get_sprite(game);
    while(xi < (WIDTH / CHUNCK_SIZE))
    {
        yi = 0;
        while(yi < (WIDTH / CHUNCK_SIZE))
        {
            color = get_color(&game->map.player.textures[type].img.addr, game->map.player.textures[type].width, yi / 2, xi / 2);
            if(*(unsigned int*)color != 0)
            {
                if(x + xi >= 0 && x + xi <= WIDTH && y + yi >= 0 && y + yi <= WIDTH)
                    pixel_put(&game->image, x + xi, y + yi, *(unsigned int*)color);
            }

            yi++;
        }
        xi++;
    }
}


int draw_player(t_game *game)
{

    t_player player;

    player = game->map.player;

    die(game);

    if(player.die == 0)
    {
        always_on_ground(game);
        if(player.finished == 0)
        {
            apply_inertie(game);
            if(game->time / STEP_TIME != game->map.player.step_time)
            {
                game->map.player.step++;
                if(game->map.player.step > 2)
                    game->map.player.step = 0;
            }
        }   
    }

    // printf("%d\n", player.y);

    draw_player_at(game, player.x, player.y);

    return (1);
}