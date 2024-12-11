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

void background_grass(t_mlx data)
{
	int width;
    int height;

	height = 0;    
    while (height < 480)
	{
		width = 0;
		while(width < 1152)
        {
			mlx_put_image_to_window(data.mlx, data.window, data.backgroung, width, height);
            width += 48;
        }
        height += 48;
	}
}
t_mlx	initialise_stuff(t_mlx data)
{
	data.tile_width = 48;		//this is dependent on location of p
	data.tile_height = 48;		//this is dependent on location of p
	data.moves = 1;
	return (data);
}

void window_main(void)
{
	t_mlx   data;
    t_map   map_data;
	data.mlx = mlx_init ();
	if (!data.mlx)
		return (0);
	data.window = mlx_new_window(data.mlx, 1152, 480, "so_long"); //considering each block to be 48x48 itll be 24*12
	if (!data.window)
		return (0);		//destroy window function, free stuff, return error
	
    data = save_images(data);
	data = initialise_stuff(data);
	background_grass(data);
    map_data = beginning();

    //ft_printf("%s\n", map_data.map[0]);
    map_parsing(map_data, data);
	//to get key response
	mlx_key_hook(data.window, &events, &data);
	
	//to put the shroom
	
	
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.shroom_image);
    mlx_destroy_image(data.mlx, data.obstacle);
    mlx_destroy_image(data.mlx, data.end_open);
    mlx_destroy_image(data.mlx, data.end_closed);
    mlx_destroy_image(data.mlx, data.collectible);
    mlx_destroy_image(data.mlx, data.backgroung);
	mlx_destroy_window(data.mlx, data.window);
	//mlx_destroy_display(data.mlx);
	free(data.mlx);
	free(data.shroom_image);
	free(data.window);
	//exit(0);
}

