#include"so_long.h"

void	free_copy(t_path *map, t_mlx data)
{
	int i;

    i = 0;
    while(i < data.l_count)
        free(map->map_cpy[i++]);
    free(map->map_cpy);
    free(map);
}

void	free_map(char **map)
{
	int i;

    i = 0;
    while(map[i])
	{
        free(map[i]);
		i++;
	}
    free(map);
	map = NULL;
}

void	destroy_everything(t_mlx data)
{
	if (data.shroom_image)
		mlx_destroy_image(data.mlx, data.shroom_image);
    if (data.obstacle)
        mlx_destroy_image(data.mlx, data.obstacle);
    if (data.end_open)
        mlx_destroy_image(data.mlx, data.end_open);
    if (data.end_closed)
        mlx_destroy_image(data.mlx, data.end_closed);
    if (data.collectible)
        mlx_destroy_image(data.mlx, data.collectible);
    if (data.backgroung)
        mlx_destroy_image(data.mlx, data.backgroung);
    if (data.window)
		mlx_destroy_window(data.mlx, data.window);
	if (data.mlx)
    {
		mlx_destroy_display(data.mlx);
        free(data.mlx);
    }
	free_map(data.map);
}
