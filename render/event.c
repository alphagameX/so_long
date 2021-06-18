#include "../source/so_long.h"


int close_window(int key, t_game *game)
{
    if(key == 65307)
    {
        mlx_do_key_autorepeaton(game->mlx);
        exit(0);
    }
    return (1);
}

int hit(t_game *game, t_player player)
{
    int x0;
    int x1;
    int y0;
    int y1;

    if(game->map.chunk.step > 0)
        player.x += game->map.chunk.step;

    x0 = (((player.x + 1) / (WIDTH / CHUNCK_SIZE)) + 1);
    x1 = (((player.x + ((WIDTH / CHUNCK_SIZE) - 1)) / (WIDTH / CHUNCK_SIZE)) + 1);
    y0 = (player.y / (HEIGHT / CHUNCK_SIZE));
    y1 = (player.y + (HEIGHT / CHUNCK_SIZE)) / (HEIGHT / CHUNCK_SIZE);

    x0 += player.chunk_cursor;
    x1 += player.chunk_cursor;

    // printf("%d\n", player.chunk_cursor);

    // printf("x0y0 : %c\n", game->map.buffer.buffer[y0][x0 + 1]);
    // printf("x1y0 : %c\n",  game->map.buffer.buffer[y0][x1 + 1]);
    // printf("x0y1 : %c\n",  game->map.buffer.buffer[y1][x0 + 1]);
    // printf("x1y1 : %c\n\n",  game->map.buffer.buffer[y1][x1 + 1]);

    if(game->map.buffer.buffer[y0][x0] == '1' || game->map.buffer.buffer[y0][x1] == '1' || 
        game->map.buffer.buffer[y1][x0] == '1' || game->map.buffer.buffer[y1][x1] == '1')
    
    {
        if((game->map.buffer.buffer[y0][x1] == '1' && game->map.buffer.buffer[y1][x1] == '0') ||
            game->map.buffer.buffer[y0][x0] == '1' &&   game->map.buffer.buffer[y1][x0] == '0')
        {

            if(game->map.buffer.buffer[(player.y + 1) / (HEIGHT / CHUNCK_SIZE)][x1] == '1' || game->map.buffer.buffer[(player.y + 1) / (HEIGHT / CHUNCK_SIZE)][x0] == '1')
                return (1);

            return (0);
        } 

        
      

        return (1);
    }
    return (0);
}

int player_move(int key, t_game *game)
{

    t_player *player = &game->map.player;

    if(key == 65361)
    {
        if(player->x >= 0)
        {
            player->moving = 1;
            player->dir = -1;
            player->x -= STEP;
            if(hit(game, *player)) {
                player->x += STEP;
                player->moving = 0;
            }
        }
    }
    if(key == 65363)
    {
       
        player->moving = 1;
        player->dir = 1;

        if(player->x < WIDTH / 2 || !(game->map.chunk.cursor <= ((ft_strlen(game->map.buffer.buffer[0]) - 1) - CHUNCK_SIZE) - 1))
        {
            player->scrolling = 0;
            player->x += STEP;
            if(hit(game, *player)) {
                player->x -= STEP;
                player->moving = 0;    
            }
        } else {

            player->scrolling = 1;
            player->chunk_cursor += move_chunk_right(game);

            if(hit(game, *player))
            {
                player->chunk_cursor -= move_chunk_left(game);
                player->moving = 0;
            }
        }
        
    }
    if(key == 32 || key == 65362)
    {
        if(player->falling == 0)
        {
            if(player->y > player->previous_y - ((WIDTH / CHUNCK_SIZE) * 3.5))
            {
                player->y -= STEP;
                player->jumping = 1;
                if(hit(game, *player)) {
                    player->y += STEP;
                    unregister_key(key, game);
                }
            }
            else
            {
                unregister_key(key, game);
            }
        }
    }
    if(key == 65364)
    {
        player->y += STEP;

        if(hit(game, *player)) {
            player->y -= STEP;
        }
    }
    return (1);
}

