#include "../source/so_long.h"


int close_window(int key, t_game *game)
{
    if(key == 65307)
    {
        exit(0);
    }
    return (1);
}



int player_move(int key, t_game *game)
{
    if(key == 65361)
    {

        


        game->map.player.step_x -= 1;
        if(game->map.player.step_x <= 0)
        {
            game->map.player.x--;
            game->map.player.step_x = (WIDTH / game->map.chunk.size);
        }

        printf("%c\n", game->map.buffer.buffer[game->map.player.y][game->map.player.x]);
    }
    if(key == 65363)
    {
        game->map.player.step_x += 1;
        if(game->map.player.step_x >= (WIDTH / game->map.chunk.size))
        {
            game->map.player.x++;
            game->map.player.step_x = 0;
        }

        printf("%c\n", game->map.buffer.buffer[game->map.player.y][game->map.player.x]);
    }
    if(key == 32 || key == 65362)
    {
        game->map.player.step_y -= 1;
        if(game->map.player.step_y <= 0)
        {
            game->map.player.y--;
            game->map.player.step_y = (WIDTH / game->map.chunk.size);
        }

        printf("%c\n", game->map.buffer.buffer[game->map.player.y][game->map.player.x]);
    }


    if(key == 65364)
    {
        game->map.player.step_y += 1;
        if(game->map.player.step_y >= (WIDTH / game->map.chunk.size))
        {
            game->map.player.y++;
            game->map.player.step_y = 0;
        }

        printf("%c\n", game->map.buffer.buffer[game->map.player.y][game->map.player.x]);
    }
   
    return (1);
}