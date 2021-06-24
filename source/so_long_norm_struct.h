#ifndef SO_LONG_NORM_STRUCT
#define SO_LONG_NORM_STRUCT

typedef struct s_checking_map
{
    int y;
    int x;
    int c;
    int p; 
    int e;
} t_checking_map;

typedef struct s_hit 
{
    int x0;
    int x1;
    int y0;
    int y1;
}   t_hit;

typedef struct s_draw_block
{
    int x;
    int y;
    int width;
    int height;
    int type;
    int yi;
    int xi;
}   t_draw_block;

/*
** NORM
**
*/

t_checking_map init_checking_map(void);
t_hit	init_hit(t_game *game, t_player player);
int	_h(char c);

#endif