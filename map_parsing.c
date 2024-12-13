#include "so_long.h"

//2d array of map
//initialise window size to line len and line count * 48
//map_data.map[y][x] --> y up/down | x --> right left
//location on window would be x * 48
	//y = 0 | height = 0
	//x = 0 | lenght = 0
	//y = 1	| height = 48
//save coordinates of shroomie

#include<stdio.h>
void	char_location(t_mlx *data, int x, int y)
{
	data->x_char = x * data->tile_width;
	data->y_char = y * data->tile_height;
}

void    end_location(t_mlx *data, int x, int y)
{
    data->x_end = x * data->tile_width;
	data->y_end = y * data->tile_height;
}

void map_parsing(t_map map_data, t_mlx *mlx_data)
{
	int	y;
	int x;

	y = 0;
	while(y < map_data.l_count)
	{
		x = 0;
		while(x < map_data.l_len)
		{
			if (map_data.map[y][x] == 'P')
			{	
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->window, mlx_data->shroom_image, (x * 48), (y * 48));
				char_location(mlx_data, x, y);
			}
			if (map_data.map[y][x] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->window, mlx_data->obstacle, (x * 48), (y * 48));
			if (map_data.map[y][x] == 'E')
            {
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->window, mlx_data->end_closed, (x * 48), (y * 48));
                end_location(mlx_data, x, y);
            }
            if (map_data.map[y][x] == 'C')
            {
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->window, mlx_data->collectible, (x * 48), (y * 48));
                mlx_data->collectible_count++;
            }
			x++;
		}
		y++;
	}
}
