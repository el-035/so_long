#include"so_long.h"

//fix makefile (libft)
//valgrind
//error invalid number of args or wrong file why success
//do i print you won at the end??
//remove -g from makefile compilation
// ext 0 r 1
//check that map is not bigger than display
//if collectoble cannot be reached invalid map

void	map_input(char *map_file)
{
	int i;

	i = ft_strlen(map_file) - 1;
	if (map_file[i] != 'r' || map_file[i - 1] != 'e' || map_file[i - 2] != 'b' || map_file[i - 3] != '.')
	{
		perror("Error opening map");
		exit (1);
	}
}

int main (int argc, char **argv)
{
	t_mlx		data;

	if (argc != 2)
	{
		perror("Invalid number of arguments");
		exit (1);
	}
	map_input(argv[1]);
	data.mlx = mlx_init ();
	if (!data.mlx)
		errors("Allocation failed", data);
	data = initialise_stuff(data);
	data = save_images(data);
	data = map(data, argv[1]);
	data.window = mlx_new_window(data.mlx, (data.l_len * data.tile_width), (data.l_count * data.tile_height), "so_long");
	if (!data.window)
		errors("Allocation failed", data);
	background_grass(data);
	map_parsing(&data);
	mlx_hook(data.window, 17, 0, destroy_everything, &data);
	mlx_key_hook(data.window, &events, &data);
	mlx_loop(data.mlx);
}