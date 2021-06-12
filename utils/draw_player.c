#include "../source/so_long.h"

void draw_player_at(t_game *game, int x, int y)
{

    int xi;
    int yi;
    char *color;

    xi = 0;
    while(xi < (WIDTH / game->map.chunk.size))
    {
        yi = 0;
        while(yi < (WIDTH / game->map.chunk.size))
        {

            color = get_color(&game->map.player.textures[0].img.addr, game->map.player.textures[0].width, yi / 2, xi / 2);
            if(*(unsigned int*)color != 0)
            {
                if(x + xi >= 0 && x + xi <= WIDTH && y + yi >= 0 && y + yi <= WIDTH)
                    pixel_put(&game->image, x + xi, y + yi, *(unsigned int*)color);
            }


            if(xi >= 0 && xi < 5 && yi >= 0 && yi <= 5)
            {
                pixel_put(&game->image, x + xi, y +yi, 0xFFFFFFF);
            }

            if(xi >= (WIDTH / game->map.chunk.size) - 5 && xi < (WIDTH / game->map.chunk.size) && yi >= 0 && yi <= 5)
            {
                pixel_put(&game->image, x + xi, y +yi, 0xFFFFFFF);
            }

            if(xi >=  0 && xi < 5 && yi >= (WIDTH / game->map.chunk.size) - 5 && yi <= (WIDTH / game->map.chunk.size))
            {
                 pixel_put(&game->image, x + xi, y +yi, 0xFFFFFFF);
            }

            if (xi >= (WIDTH / game->map.chunk.size) - 5 && xi < (WIDTH / game->map.chunk.size) && yi >= (WIDTH / game->map.chunk.size) - 5 && yi <= (WIDTH / game->map.chunk.size))
            {
                pixel_put(&game->image, x + xi, y +yi, 0xFFFFFFF);
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

    int x = (WIDTH / game->map.chunk.size) * (player.x - 1);
    int y = HEIGHT - ((WIDTH / game->map.chunk.size) * (game->map.buffer.count - player.y));


    // print_sarray(game->map.buffer);

    draw_player_at(game, x + player.step_x , y + player.step_y);

    return (1);
}