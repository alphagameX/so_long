#include "../source/so_long.h"


int get_block_type(t_map map, int x, int y)
{	

	if(y >= map.buffer.count - 2)
		return (1);

	if(y == 0)
		return (-1);
	
	if(x > 0 && x < ft_strlen(map.buffer.buffer[y]))
	{
		if(map.buffer.buffer[y][x] == '1' && map.buffer.buffer[y + 1][x] == '0' && map.buffer.buffer[y - 1][x] == '0')
			return (0);
	}
	
	return (2);
}

int move_chunk_right(t_game *game)
{
	int size_of_all_block;
    int block;

    block = WIDTH / game->map.chunk.size;
    size_of_all_block = block * game->map.chunk.size;
	if(game->map.chunk.cursor <= ((ft_strlen(game->map.buffer.buffer[0]) - 1) - game->map.chunk.size) - 1)
	{
		game->map.chunk.step += STEP;
		if(game->map.chunk.step >= block - (WIDTH - size_of_all_block))
		{
			game->map.chunk.cursor++;
			game->map.chunk.step = 0;
		}


		game->map.chunk.dir = 1;     
	}
}


int move_chunk_left(t_game *game)
{
	if(game->map.chunk.cursor > 0)
	{
		if(game->map.chunk.step > 0)
			game->map.chunk.step -= STEP;

		if(game->map.chunk.step == 0 && game->map.chunk.cursor > 1)
		{          
			game->map.chunk.cursor--;
			game->map.chunk.step = (WIDTH / game->map.chunk.size);
		}

		game->map.chunk.dir = 0;
	}
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
			if(x / (WIDTH / game->map.chunk.size) == 0 )
			{
				if((drawX - xi) >= 0 && (drawX - xi) <= WIDTH && (y + yi) >= 0 && (y + yi) <= HEIGHT)
				{
					if (type != -1)
					{
						color = get_color(&game->textures[type].img.addr, game->textures[type].width , yi / 2, ((WIDTH / game->map.chunk.size) - xi) / 2);
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

	if(block * game->map.chunk.size == WIDTH)
		{
			if(x / block == game->map.chunk.size - 1 && game->map.chunk.step > 0)
			{
				y = 0;
				while(y < game->map.buffer.count)
				{
					if(game->map.buffer.buffer[(game->map.buffer.count - 1) - y][(game->map.chunk.cursor + (x / block)) + 1] == '1')
					{
						block_type = get_block_type(game->map, (game->map.chunk.cursor + (x / block)) + 1, (game->map.buffer.count - 1) - y);
						draw_block(game, (x + block) - game->map.chunk.step, HEIGHT - (block * (y + 1)), game->map.chunk.step, block, block_type);
					}
					else
						draw_block(game, (x + block) - game->map.chunk.step, HEIGHT - (block * (y + 1)), game->map.chunk.step, block, -1);

					y += 1;
				}
			}
		}

}


int draw_map(t_game *game)
{
	int block = WIDTH / game->map.chunk.size;
	int x = 0;
	int y;
	int block_type;



	while(x < WIDTH)
	{
		y = 0; 
		while(y < game->map.buffer.count)
		{
			if( game->map.buffer.buffer[(game->map.buffer.count - 1) - y][game->map.chunk.cursor + (x / block)] == '1')
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

		draw_last_block(game, x, block);
		
		x += block;
	}
	return (1);
}