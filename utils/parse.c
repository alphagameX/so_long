#include "../source/so_long.h"



t_sarray parse_map(char *path)
{

    int fd;
    int ret;
    char *line;
    t_sarray array;


    array = new_sarray();
    fd = open(path, O_RDONLY);

    ret = 1;
    while(ret)
    {   
        ret = get_next_line(fd, &line);
        push_sarray(line to array);
    }
    return array;
}

t_player get_spawn(t_sarray array)
{
    int x;
    int y;
    t_player player;

    x = 0;
    while(array.buffer[x])
    {
        y = 0;
        while(y < array.count)
        {
            if(array.buffer[y][x] == 'P')
            {
                player.spawn_x = x;
                player.spawn_y = y;
                return player;
            }
            y++;
        }
        x++;
    }

    exit(0);
}

void checking_map(t_sarray *array, t_game *game)
{
    int y;
    int x;

    if(array->count < 25)
        exit_game(game);


    y = 0;
    while(y < array->count)
    {
        x = 0;
        while(x < ft_strlen(array->buffer[y]))
        {
            if(array->buffer[y][x] == '0' || array->buffer[y][x] == 'E' || array->buffer[y][x] == 'P' || array->buffer[y][x] == 'C')
            {
                if(y == 0 || x == 0 || x == ft_strlen(array->buffer[y]) - 1 || y == array->count - 1)
                    exit_game(game);
                if((array->buffer[y + 1][x] == '1' || array->buffer[y + 1][x] == '0' || array->buffer[y + 1][x] == 'E' || array->buffer[y + 1][x] == 'P' || array->buffer[y + 1][x] == 'C') &&
                   (array->buffer[y - 1][x] == '1' || array->buffer[y - 1][x] == '0' || array->buffer[y - 1][x] == 'E' || array->buffer[y - 1][x] == 'P' || array->buffer[y - 1][x] == 'C') && 
                   (array->buffer[y][x + 1] == '1' || array->buffer[y][x + 1] == '0' || array->buffer[y][x + 1] == 'E' || array->buffer[y][x + 1] == 'P' || array->buffer[y][x + 1] == 'C') &&
                   (array->buffer[y][x - 1] == '1' || array->buffer[y][x - 1] == '0' || array->buffer[y][x - 1] == 'E' || array->buffer[y][x - 1] == 'P' || array->buffer[y][x - 1] == 'C'))
                {
                    array->buffer[y][x] = '1';
                }
            }
            x++;
        }
        y++;
    }

    y = 0;
    while(y < array->count)
    {
        x = 0;
        while(x < ft_strlen(array->buffer[y]))
        {
            if(array->buffer[y][x] != '1')
                exit_game(game);
            x++;
        }
        y++;
    }

    free_sarray(&game->map.buffer);
    game->map.buffer = parse_map("map.ber");
}

void interpret_map(t_sarray *array, t_game *game)
{
    int y;
    int x;

    y = 0;
    while(y < array->count)
    {
        x = 0;
        while(x < ft_strlen(array->buffer[y]))
        {
            if(y + 1 < array->count - 1)
            {
               if(array->buffer[y][x] == '1')
               {
                    if(array->buffer[y + 1][x] == '0' && array->buffer[y - 1][x] == '0')
                    {
                        array->buffer[y][x] = 'B';
                    }
               }
            } else {
                if(array->buffer[y][x] == '1')  
                    array->buffer[y][x] = 'G';
            }
            x++;
        }
        y++;
    }

    print_sarray(*array);
    exit_game(game);
}