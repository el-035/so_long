#include "so_long.h"

void	char_location(t_mlx *data, int x, int y)
{
	data->x_char = x * data->tile_width;
	data->y_char = y * data->tile_height;
}

void	end_location(t_mlx *data, int x, int y)
{
	data->x_end = x * data->tile_width;
	data->y_end = y * data->tile_height;
}

void	parsing_conditions(t_mlx *data, int x, int y)
{
	if (data->map[y][x] == 'P')
	{	
		mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, (x * 48), (y * 48));
		char_location(data, x, y);
	}
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->obstacle, (x * 48), (y * 48));
	if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->end_closed, (x * 48), (y * 48));
		end_location(data, x, y);
	}
	if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->collectible, (x * 48), (y * 48));
		data->collectible_count++;
	}
}

void map_parsing(t_mlx *data)
{
	int	y;
	int x;

	y = 0;
	while(y < data->l_count)
	{
		x = 0;
		while(x < data->l_len)
		{
			parsing_conditions(data, x, y);
			x++;
		}
		y++;
	}
}
