#include "so_long.h"

t_mlx   save_images(t_mlx data) //fix error messages
{
    int height;
    int width;

    data.backgroung = mlx_xpm_file_to_image(data.mlx, "images/Grass.xpm", &width, &height);
    if (!data.backgroung)
		exit (1);
    data.shroom_image = mlx_xpm_file_to_image(data.mlx, "images/shroomie.xpm", &width, &height);
	if (!data.shroom_image)
		exit (1);
    data.obstacle = mlx_xpm_file_to_image(data.mlx, "images/obstacle.xpm", &width, &height);
	if (!data.obstacle)
		exit (1);
    data.end_open = mlx_xpm_file_to_image(data.mlx, "images/open_chest.xpm", &width, &height);
	if (!data.end_open)
		exit (1);
    data.end_closed = mlx_xpm_file_to_image(data.mlx, "images/closed_chest.xpm", &width, &height);
	if (!data.end_closed)
		exit (1);
    data.collectible = mlx_xpm_file_to_image(data.mlx, "images/key.xpm", &width, &height);
    if (!data.collectible)
		exit (1);
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
	data.tile_width = 48;		//this is dependent on location of p
	data.tile_height = 48;		//or maybe its just not
	data.moves = 1;
    data.map = map_data.map;
    data.collectible_count = 0;
	return (data);
}

