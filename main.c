#include"so_long.h"

//fix makefile (libft)
//valgrind
//error invalid number of args

void	map_input(char *map_file)
{
	int i;

	i = ft_strlen(map_file) - 1;
	if (map_file[i] != 'r' || map_file[i - 1] != 'e' || map_file[i - 2] != 'b' || map_file[i - 3] != '.')
		errors("Error opening map");
}

int main (int argc, char **argv)
{
	t_mlx		data;

	if (argc != 2)
		errors("Invalid number of arguments");
	map_input(argv[1]);
	data.mlx = mlx_init ();
	if (!data.mlx)
		errors("Allocation failed");	//destroy everything ??
	data = map(data, argv[1]);
	data = save_images(data);
	data = initialise_stuff(data);
	data.window = mlx_new_window(data.mlx, (data.l_len * data.tile_width), (data.l_count * data.tile_height), "so_long");
	if (!data.window)
	{
		destroy_everything(data);
		errors("Allocation failed");
	}
	background_grass(data);
	map_parsing(&data);
	mlx_key_hook(data.window, &events, &data);
	mlx_hook(data.window, 17, 0, close_everything, &data);
	mlx_loop(data.mlx);
	exit(0);
}