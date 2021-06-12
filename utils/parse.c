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
            if(array.buffer[y][x] == 'C')
            {
                player.x = x;
                player.y = y;
                player.step_x = 0;
                player.step_y = 0;
                return player;
            }
            y++;
        }
        x++;
    }

    exit(0);
}