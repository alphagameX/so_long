#include "../../source/so_long.h"

int _h(char c)
{
    if(c == '1' || c == 'G' || c == 'B' || c == '2' || c == '3' || c == '4' || c == '5')
        return (1);
    return (0);
}

int hit(t_game *game, t_player player)
{
    int x0;
    int x1;
    int y0;
    int y1;

    if(game->map.chunk.step > 0)
        player.x += game->map.chunk.step;
    x0 = (((player.x + STEP) / (WIDTH / CHUNCK_SIZE)) + 1);
    x1 = (((player.x + ((WIDTH / CHUNCK_SIZE) - STEP)) / (WIDTH / CHUNCK_SIZE)) + 1);
    y0 = (player.y / (HEIGHT / CHUNCK_SIZE));
    y1 = (player.y + (HEIGHT / CHUNCK_SIZE)) / (HEIGHT / CHUNCK_SIZE);
    x0 += player.chunk_cursor;
    x1 += player.chunk_cursor;
    if(_h(game->map.buffer.buffer[y0][x0]) || 
       _h(game->map.buffer.buffer[y0][x1]) || 
       _h(game->map.buffer.buffer[y1][x0]) || 
       _h(game->map.buffer.buffer[y1][x1]))
    {
        if((_h(game->map.buffer.buffer[y0][x1]) && game->map.buffer.buffer[y1][x1] == '0') ||
            (_h(game->map.buffer.buffer[y0][x0]) && game->map.buffer.buffer[y1][x0] == '0'))
        {
            if(_h(game->map.buffer.buffer[(player.y + STEP) / (HEIGHT / CHUNCK_SIZE)][x1]) || _h(game->map.buffer.buffer[(player.y + STEP) / (HEIGHT / CHUNCK_SIZE)][x0]))
            {
                return (1);
            }
            return (0);
        } 
        return (1);
    }

    if(player.y  >= (HEIGHT - (WIDTH / CHUNCK_SIZE)) - STEP)
    {
        game->map.player.die = 1;
        return (1);
    }

    if(game->map.buffer.buffer[y1][x1] == 'C')
    {
        game->map.buffer.buffer[y1][x1] = '0';
        game->map.player.coin++;
    }

    if(game->map.buffer.buffer[y1][x0] == 'C')
    {
        game->map.buffer.buffer[y1][x0] = '0';
        game->map.player.coin++;
    }

    if(game->map.buffer.buffer[y1][x0] == 'M')
    {
        game->map.player.finished = 1;
    }

    return (0);
}

void right(t_player *player, t_game *game)
{
    int move;

    player->moving = 1;
    player->dir = 1;
    if(player->x < WIDTH / 2 || !(game->map.chunk.cursor <= ((ft_strlen(game->map.buffer.buffer[0]) - 1) - CHUNCK_SIZE) - 1))
    {
        player->scrolling = 0;
        player->x += STEP;
        if(player->x % (WIDTH / CHUNCK_SIZE) == 0)
            player->move++;
        if(hit(game, *player))
        {
            player->x -= STEP;
            player->moving = 0;    
        }
    } else {
        player->scrolling = 1;
        move = move_chunk_right(game);
        player->chunk_cursor += move;
        player->move += move;
        if(hit(game, *player))
        {
            player->chunk_cursor -= move_chunk_left(game);
            player->moving = 0;
        }
    }
}

void left(t_player *player, t_game *game)
{
    player->moving = 1;
    player->dir = -1;
    if(player->x >= 0)
    {
        player->x -= STEP;
        if(player->x % (WIDTH / CHUNCK_SIZE) == 0)
            player->move++;
        if(hit(game, *player)) {
            player->x += STEP;
            player->moving = 0;
        }
    }
}

void up(t_player *player, t_game *game)
{
    if(player->falling == 0)
    {
        if(player->y > player->previous_y - ((WIDTH / CHUNCK_SIZE) * 4))
        {
            player->y -= STEP;
            player->jumping = 1;
            if(hit(game, *player)) {
                player->y += STEP;
                unregister_key(UP, game);
            }
        }
        else
            unregister_key(UP, game);
    }
}

int player_move(int key, t_game *game)
{
    t_player *player;

    player = &game->map.player;
    if(player->die == 0 && player->finished == 0)
    {
        if(key == LEFT)
            left(player, game);
        if(key == RIGHT)
            right(player, game);
        if(key == UP)
            up(player, game);
    }
    return (1);
}

