#include "../../source/so_long.h"


int get_block_type(t_map map, int x, int y)
{	
	if(map.buffer.buffer[y][x] == 'C')
		return (3);
	if(map.buffer.buffer[y][x] == 'G')
		return (0);
	if(y == 0 || map.buffer.buffer[y][x] == 'V')
		return (-1);
	if(map.buffer.buffer[y][x] == 'B')
		return (1);
	if(map.buffer.buffer[y][x] == 'M')
		return (4);
	if(map.buffer.buffer[y][x] == 'W')
		return (5);
	if(map.buffer.buffer[y][x] == 'U')
		return (6);
	if(map.buffer.buffer[y][x] == 'T')
		return (8);
	if(map.buffer.buffer[y][x] == 'I')
		return (7);
	if(map.buffer.buffer[y][x] == '2')
		return (9);
	if(map.buffer.buffer[y][x] == '3')
		return (10);
	if(map.buffer.buffer[y][x] == '4')
		return (11);
	if(map.buffer.buffer[y][x] == '5')
		return (12);
	return (2);
}


void draw_block(t_game *game, int x, int y, int width, int height, int type)
{
	int xi;
	int yi;
	char *color;
	int drawX = x + width;

	xi = 0;
	while(xi < width)
	{
		yi = 0;
		while(yi < height)
		{
			if(x / (WIDTH / CHUNCK_SIZE) == 0 )
			{
				if((drawX - xi) >= 0 && (drawX - xi) <= WIDTH && (y + yi) >= 0 && (y + yi) <= HEIGHT)
				{
					if (type != -1)
					{
						color = get_color(&game->textures[type].img.addr, game->textures[type].width , yi / 2, ((WIDTH / CHUNCK_SIZE) - xi) / 2);
						pixel_put(&game->image, drawX - xi , y + yi, *(unsigned int *)color);
					}
					else
					{
						pixel_put(&game->image,  drawX - xi , y + yi, 0xa1aeff);
					}
				}
			}
			else
			{
				if(x + xi <= WIDTH && y + yi <= HEIGHT && x + xi >= 0 && y + yi >= 0)
				{
					if (type != -1)
					{
						color = get_color(&game->textures[type].img.addr, game->textures[type].width , yi / 2, xi / 2);
						pixel_put(&game->image, x + xi , y + yi, *(unsigned int *)color);
					}
					else
					{
						pixel_put(&game->image, x + xi, y + yi, 0xa1aeff);
					}
				}
			}
			yi++;
		}
		xi++;
	}	
}


void draw_last_block(t_game *game, int x, int block)
{

	int y;
	int block_type;

	y = 0;
	while(y < game->map.buffer.count)
	{
		if(_h(game->map.buffer.buffer[(game->map.buffer.count - 1) - y][(game->map.chunk.cursor + (x / block)) + 1]))
		{
			block_type = get_block_type(game->map, (game->map.chunk.cursor + (x / block)) + 1, (game->map.buffer.count - 1) - y);
			draw_block(game, (x + block) - game->map.chunk.step, HEIGHT - (block * (y + 1)), game->map.chunk.step, block, block_type);
		}
		else
			draw_block(game, (x + block) - game->map.chunk.step, HEIGHT - (block * (y + 1)), game->map.chunk.step, block, -1);
		y += 1;
	}
		

}


int draw_map(t_game *game)
{
	int block = WIDTH / CHUNCK_SIZE;
	int x = 0;
	int y;
	int block_type;
	char c;

	while(x < WIDTH)
	{
		y = 0; 
		while(y < game->map.buffer.count)
		{
			c = game->map.buffer.buffer[(game->map.buffer.count - 1) - y][game->map.chunk.cursor + (x / block)];
			if(_h(c) || c == 'C' || c == 'M' || c == 'T' || c == 'I' || c == 'U' || c == 'W')
			{

				block_type = get_block_type(game->map, game->map.chunk.cursor + (x / block) ,(game->map.buffer.count - 1) - y );

				if(x / block == 0) {
					draw_block(game, x, HEIGHT - (block * (y + 1)) , block - game->map.chunk.step, block, block_type);
				}
				else
					draw_block(game, x - game->map.chunk.step, HEIGHT - (block * (y + 1)) , block, block, block_type);
			
			} else {
				draw_block(game, x - game->map.chunk.step, HEIGHT - (block * (y + 1)) , block, block, -1);
			}



			y++;
		}

		if(block * CHUNCK_SIZE == WIDTH)
		{
			if(x / block == CHUNCK_SIZE - 1 && game->map.chunk.step > 0)
			{
				draw_last_block(game, x, block);
			}
		}

		
		x += block;
	}

	return (1);
}