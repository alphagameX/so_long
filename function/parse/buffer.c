#include "../../source/so_long.h"

void check_item(t_game *game, t_checking_map i)
{
    if(i.e == 0 || i.e > 1)
    {
        ft_putstr("Error\n");
        ft_putstr("There is not or too many E (exit)\n");
        exit_game(game);
    }
    if(i.p == 0 || i.p > 1)
    {
        ft_putstr("Error\n");
        ft_putstr("There is not or too many P (spawn)\n");
        exit_game(game);
    }
    if(i.c == 0)
    {
        ft_putstr("Error\n");
        ft_putstr("There is not C (collectible)\n");
        exit_game(game);
    }
}

void is_valid_map(t_game *game, t_sarray *array)
{
    int y;
    int x;

    y = 0;
    while(y < array->count)
    {
        x = 0;
        while(x < ft_strlen(array->buffer[y]))
        {
            if(array->buffer[y][x] != '1')
            {
                ft_putstr("Error\n");
                ft_printf("Map have unknown character at %d:%d\n", y, x);
                exit_game(game);
            }
            x++;
        }
        y++;
    }
}

void arround_zero(t_game *game, t_sarray *array, t_checking_map i)
{
    if(i.y == 0 || i.x == 0 || i.x == ft_strlen(array->buffer[i.y]) - 1 || i.y == array->count - 1)
    {
        ft_putstr("Error\n");
        ft_printf("Map have 0 on border at %d:%d\n", i.y, i.x);
        exit_game(game);
    }
    if((array->buffer[i.y + 1][i.x] == '1' || array->buffer[i.y + 1][i.x] == '0' ||
        array->buffer[i.y + 1][i.x] == 'E' || array->buffer[i.y + 1][i.x] == 'P' || 
        array->buffer[i.y + 1][i.x] == 'C') &&
       (array->buffer[i.y - 1][i.x] == '1' || array->buffer[i.y - 1][i.x] == '0' ||
        array->buffer[i.y - 1][i.x] == 'E' || array->buffer[i.y - 1][i.x] == 'P' ||
        array->buffer[i.y - 1][i.x] == 'C') && 
       (array->buffer[i.y][i.x + 1] == '1' || array->buffer[i.y][i.x + 1] == '0' ||
        array->buffer[i.y][i.x + 1] == 'E' || array->buffer[i.y][i.x + 1] == 'P' ||
        array->buffer[i.y][i.x + 1] == 'C') &&
       (array->buffer[i.y][i.x - 1] == '1' || array->buffer[i.y][i.x - 1] == '0' ||
        array->buffer[i.y][i.x - 1] == 'E' || array->buffer[i.y][i.x - 1] == 'P' ||
        array->buffer[i.y][i.x - 1] == 'C'))
    {
        array->buffer[i.y][i.x] = '1';
    }
}

void add_item(t_sarray *array, t_checking_map *i, t_game *game)
{
    if(array->buffer[i->y][i->x] == 'E')
        i->e++;
    if(array->buffer[i->y][i->x] == 'P')
    {
        i->p++;
        if(i->x > CHUNCK_SIZE)
        {
            ft_putstr("Error\n");
            ft_putstr("The spawn is not in the first chunk (25 block)\n");
            exit_game(game);
        }
    }
    if(array->buffer[i->y][i->x] == 'C')
        i->c++;
}

void checking_map(t_sarray *array, t_game *game)
{
    t_checking_map i;
    
    i = init_checking_map(); 
    if(array->count < 25)
        exit_game(game);
    while(i.y < array->count)
    {
        i.x = 0;
        while(i.x < ft_strlen(array->buffer[i.y]))
        {
            if(array->buffer[i.y][i.x] == '0' || array->buffer[i.y][i.x] == 'E' || array->buffer[i.y][i.x] == 'P' || array->buffer[i.y][i.x] == 'C')
            {
                add_item(array, &i, game);
                arround_zero(game, array, i);
            }
            i.x++;
        }
        i.y++;
    }
    is_valid_map(game, array);
    check_item(game, i);
    game->map.coin = i.c;
    free_sarray(&game->map.buffer);
    game->map.buffer = parse_map(game);
}
