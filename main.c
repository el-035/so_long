#include"so_long.h"

void	map_input(char *map_file)
{
	int i;

	i = ft_strlen(map_file) - 1;
	if (map_file[i] != 'r' || map_file[i - 1] != 'e' || map_file[i - 2] != 'b' || map_file[i - 3] != '.')
		errors("Error opening map");
}

t_map map_main (char *map_file)
{
	t_map	*data;

	data = (t_map *) malloc(sizeof(t_map));
	if (!data)
		errors("Allocation failed");
	map(data, map_file);
	/* if(!data->map)
		exit (1); */
	return (*data);
}

void	destroy_everything(t_mlx data)
{
	mlx_destroy_image(data.mlx, data.shroom_image);
	mlx_destroy_image(data.mlx, data.obstacle);
	mlx_destroy_image(data.mlx, data.end_open);
	mlx_destroy_image(data.mlx, data.end_closed);
	mlx_destroy_image(data.mlx, data.collectible);
	mlx_destroy_image(data.mlx, data.backgroung);
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
/* 	free(data.mlx);
	free(data.shroom_image);
	free(data.window); */
	exit (0);
}
/* void	free_stuff(t_map map)
{
	free(map.map);
} */

void window_main(char *map_file)
{
	t_mlx		data;
	t_map		map_data;
	//t_struct	pointer;

	data.mlx = mlx_init ();
	if (!data.mlx)
		errors("Allocation failed");	//destroy everything ??
	map_data = map_main(map_file); //initialises the t_map and validates map
	data = save_images(data);
	data = initialise_stuff(data, map_data);	//initialise height and width and move count
	data.window = mlx_new_window(data.mlx, (map_data.l_len * data.tile_width), (map_data.l_count * data.tile_height), "so_long"); //considering each block to be 48x48 itll be 24*12
	if (!data.window)
		errors("Allocation failed");	//destroy window function, free stuff, return error
	background_grass(data, map_data);
	map_parsing(map_data, &data);
	mlx_key_hook(data.window, &events, &data);		//to get key response
	//close with x button
	mlx_loop(data.mlx);

	destroy_everything(data);
}

int main (int argc, char **argv)	//take map as arg
{
	if (argc != 2)
		errors("Invalid number of arguments");
	map_input(argv[1]);
	
	//initialise all structs   
	
	window_main (argv[1]);
	
}
