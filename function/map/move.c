#include "../../source/so_long.h"


int move_chunk_right(t_game *game)
{
	int size_of_all_block;
    int block;

    block = WIDTH / CHUNCK_SIZE;
    size_of_all_block = block * CHUNCK_SIZE;
	if(game->map.chunk.cursor <= ((ft_strlen(game->map.buffer.buffer[0]) - 1) - CHUNCK_SIZE) - 1)
	{
		game->map.chunk.step += STEP;
		if(game->map.chunk.step >= block - (WIDTH - size_of_all_block))
		{
			game->map.chunk.cursor++;
			game->map.chunk.step = 0;
			return (1);
		}
	}

	return (0);
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
			game->map.chunk.step = (WIDTH / CHUNCK_SIZE);
			return (1);
		}
	}

	return (0);
}