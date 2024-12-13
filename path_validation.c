#include "so_long.h"

char	**copy_map(t_map data)
{
	char	**map_cpy;
	int		y;

	map_cpy = (char **) malloc(data.l_count * sizeof(char *));
	if (!map_cpy)
		errors("Allocation failed");
	y = 0;
	while(y < data.l_count)
	{
		map_cpy[y] = ft_strdup((const char *) data.map[y]);
        if (!map_cpy[y])
            errors("Allocation failed");
		y++;
	}
	return (map_cpy);
}

int is_valid_path(t_map data, t_path path)
{
    path.y = 0;
	while(path.y < data.l_count)
	{
		path.x = 0;
		while(path.x < data.l_len)
		{
			if (path.map_cpy[path.y][path.x] == 'C' || path.map_cpy[path.y][path.x] == 'E')
				return (0);
			path.x++;
		}
		path.y++;
	}
    return (1);
}

t_path	find_p(t_map data, t_path path)
{
	path.y = 0;
	while(path.y < data.l_count)
	{
		path.x = 0;
		while(path.x < data.l_len)
		{
			if (path.map_cpy[path.y][path.x] == 'P')
				return (path);
			path.x++;
		}
		path.y++;
	}
	return (path);
}
void	fill_path(t_map data, t_path path, int x, int y)
{
    if (y < 0 || x < 0 || y >= data.l_count || x >= data.l_len || path.map_cpy[y][x] == '1')
		return ;
	path.map_cpy[y][x] = '1';
	fill_path(data, path, x + 1, y);
	fill_path(data, path, x - 1, y);
	fill_path(data, path, x, y + 1);
	fill_path(data, path, x, y - 1);
}

int	path_validation(t_map data)
{
	t_path	*path;
	path = (t_path *) malloc(sizeof(t_path));
	if (!path)
		errors("Allocation failed");
	path->map_cpy = copy_map(data);
	*path = find_p(data, *path);
    fill_path(data, *path, path->x, path->y);
	return (is_valid_path(data, *path));
}
