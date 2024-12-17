#include "so_long.h"

t_mlx   save_images(t_mlx data, t_map *map) //fix error messages
{
    int height;
    int width;

    data.backgroung = mlx_xpm_file_to_image(data.mlx, "images/Grass.xpm", &width, &height);
    if (!data.backgroung)
		destroy_everything(data, map);
    data.shroom_image = mlx_xpm_file_to_image(data.mlx, "images/shroomie.xpm", &width, &height);
	if (!data.shroom_image)
		destroy_everything(data, map);
    data.obstacle = mlx_xpm_file_to_image(data.mlx, "images/obstacle.xpm", &width, &height);
	if (!data.obstacle)
		destroy_everything(data, map);
    data.end_open = mlx_xpm_file_to_image(data.mlx, "images/open_chest.xpm", &width, &height);
	if (!data.end_open)
		destroy_everything(data, map);
    data.end_closed = mlx_xpm_file_to_image(data.mlx, "images/closed_chest.xpm", &width, &height);
	if (!data.end_closed)
		destroy_everything(data, map);
    data.collectible = mlx_xpm_file_to_image(data.mlx, "images/key.xpm", &width, &height);
    if (!data.collectible)
		destroy_everything(data, map);
	return (data);
}

void background_grass(t_mlx data, t_map map_data)
{
	int width;
    int height;

	height = 0;    
    while (height < (map_data.l_count * data.tile_height))
	{
		width = 0;
		while(width < (map_data.l_len * data.tile_width))
        {
			mlx_put_image_to_window(data.mlx, data.window, data.backgroung, width, height);
            width += data.tile_width;
        }
        height += data.tile_height;
	}
}

t_mlx	initialise_stuff(t_mlx data, t_map map_data)
{
	data.tile_width = 48;
	data.tile_height = 48;
	data.moves = 1;
    data.map = map_data.map;
    data.collectible_count = 0;
	return (data);
}
