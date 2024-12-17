#include"so_long.h"

//fix makefile (libft)
//x to close
//valgrind
//error invalid number of args

void	map_input(char *map_file)
{
	int i;

	i = ft_strlen(map_file) - 1;
	if (map_file[i] != 'r' || map_file[i - 1] != 'e' || map_file[i - 2] != 'b' || map_file[i - 3] != '.')
		errors("Error opening map");
}

t_map *map_main (char *map_file)
{
	t_map	*data;

	data = (t_map *) malloc(sizeof(t_map));
	if (!data)
		errors("Allocation failed");
	map(data, map_file);
	/* if(!data->map)
		exit (1); */
	return (data);
}

void window_main(char *map_file)
{
	t_mlx		data;
	t_map		*map_data;

	data.mlx = mlx_init ();
	if (!data.mlx)
		errors("Allocation failed");	//destroy everything ??
	map_data = map_main(map_file);
	data = save_images(data, map_data);
	data = initialise_stuff(data, *map_data);
	data.window = mlx_new_window(data.mlx, (map_data->l_len * data.tile_width), (map_data->l_count * data.tile_height), "so_long"); //considering each block to be 48x48 itll be 24*12
	if (!data.window)
	{
		//free_map(map_data);
		destroy_everything(data, map_data);
		mlx_destroy_window(data.mlx, data.window);
		errors("Allocation failed");
	}
	background_grass(data, *map_data);
	map_parsing(*map_data, &data);
	free(map_data);
	mlx_key_hook(data.window, &events, &data);
	mlx_hook(data.window, 17, 0, close_everything, &data);
	//close with x button
	mlx_loop(data.mlx);
    //free_map(map_data);
	//destroy_everything(data, NULL);
	exit(0);
}

int main (int argc, char **argv)
{
	if (argc != 2)
		errors("Invalid number of arguments");
	map_input(argv[1]);
	window_main (argv[1]);
}
