#include"so_long.h"
t_map map_main (char *map_file)
{
	t_map *data;
	data = (t_map *) malloc(sizeof(t_map));
	if (!data)
		exit (1); //error malloc
	map(data, map_file);
	if(!data->map)
		exit (1);
	return (*data);
}

void window_main(char *map_file)
{
	t_mlx   data;
    t_map   map_data;
	data.mlx = mlx_init ();
	if (!data.mlx)
		return ;
    map_data = map_main(map_file); //initialises the t_map and validates map
    data = save_images(data);
	data = initialise_stuff(data);	//initialise height and width and move count
	data.window = mlx_new_window(data.mlx, (map_data.l_len * data.tile_width), (map_data.l_count * data.tile_height), "so_long"); //considering each block to be 48x48 itll be 24*12
	if (!data.window)
		return ;		//destroy window function, free stuff, return error
	background_grass(data, map_data);
    
	map_parsing(map_data, &data);
	
	mlx_key_hook(data.window, &events, &data);		//to get key response
	//ft_printf("%c\n", map_data.map[4][9]);
	
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

int main (int argc, char **argv)	//take map as arg
{
	if (argc != 2)
		return (0);		//error
	//check that all files that need to be opened can be opened
		//all xpm
		//all maps
	//check map files end in ber aka argv 1
	//initialise all structs   
	
	window_main (argv[1]);
	//validate map						ok
	//open window						ok
		//create image of background	ok
		//create events					ok
			//moving 4 directions		ok
			//esc						ok
			//x button to close
			//parse the map
	//destroy everything
}
