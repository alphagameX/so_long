#include "../source/so_long.h"


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
    return (type);
}

void draw_player_at(t_game *game, int x, int y)
{
    int xi;
    int yi;
    char *color;
    int type;

    xi = 0;
    while(xi < (WIDTH / CHUNCK_SIZE))
    {
        yi = 0;
        while(yi < (WIDTH / CHUNCK_SIZE))
        {
            type = get_sprite(game);
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


void always_on_ground(t_game *game)
{
    t_player *player;

    player = &game->map.player;

    if(!hit(game, *player) && player->jumping == 0)
    {
        player->falling = 1;
        player->y += STEP;

        if(hit(game, *player))
        {
            player->y -= STEP;
            player->falling = 0;
            player->previous_y = player->y;
        }
    }
}

void apply_inertie(t_game *game)
{
    t_player *player;

    player = &game->map.player;
    if(player->moving == 0 && player->inertie > 0)
    {
        if(game->time / player->delay != player->inertie_time)
        {
            if(player->dir == 1)
            {
                if(player->scrolling == 0)
                {
                    player->x += STEP;
                    if(hit(game, *player))
                    {
                        player->x -= STEP * 2;
                        player->inertie = 0;
                        player->delay = 1;
                    }
                } else {
                    player->chunk_cursor += move_chunk_right(game);
                    if(hit(game, *player))
                    {
                        player->chunk_cursor -= move_chunk_left(game);
                        player->inertie = 0;
                        player->delay = 1;
                    }
                }
            }
            else if(player->dir == -1)
            {
                player->x -= STEP;
                if(hit(game, *player))
                {
                    player->x += STEP * 2;
                    player->inertie = 0;
                    player->delay = 1;
                }
            }
            player->inertie--;
            player->delay += 5;
        } 
    }
}

int draw_player(t_game *game)
{

    t_player player;

    player = game->map.player;

  
    always_on_ground(game);
    apply_inertie(game);
    
  
    if(game->time / STEP_TIME != game->map.player.step_time)
    {
        game->map.player.step++;
        if(game->map.player.step > 2)
            game->map.player.step = 0;
    }

    // printf("%d\n", player.y);

    draw_player_at(game, player.x, player.y);

    return (1);
}