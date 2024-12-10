#include"so_long.h"
#include "libft.h"  
#include <stdio.h>	//delete

//copy of the map
//look for p
//turn p into 1
//recursively call ft that turns 0 into 1 for location up down lef right
// when its over strchr E C
// if not found return 1
//else eroor map not valid

char	**copy_map(t_map data)
{
	char	**map_cpy;
	int		y;

	map_cpy = (char **) malloc(data.l_count * sizeof(char *));
	if (!map_cpy)
		return (0); //malloc error
	y = 0;
	while(y <= data.l_count)
	{
		map_cpy[y] = ft_strdup((const char *) data.map[y]);
		y++;
	}
	return (map_cpy);
}

t_path	find_p(t_map data, t_path path)
{
	path.x = 0;

	while(path.x <= data.l_len)
	{
		path.y = 0;
		while(path.y <= data.l_count)
		{
			if (path.map_cpy[path.x][path.y] == 'P')
			{
				path.map_cpy[path.x][path.y] = '1';
				return (path);
			}
			path.y++;
		}
		path.x++;
	}
	return (path);
}
void	fill_path(char **map_cpy, int x, int y)
{
	//if location is 1 return
	//else turn into 1 
	//calla agin in all other locations
	if (y < 0 || x < 0 || map_cpy[y] == NULL || map_cpy[y][x] == '\0' || map_cpy[y][x] == '\n')
		return ;
	if (map_cpy[x][y] != '1')
	{
		map_cpy[x][y] = '1';
		fill_path(map_cpy, x, y + 1);
		fill_path(map_cpy, x, y - 1);
		fill_path(map_cpy, x + 1, y);
		fill_path(map_cpy, x - 1, y);
	}
	else
		return ;
}
int	valid_path(t_map data)
{
	t_path	*path;
	path = (t_path *) malloc(sizeof(t_map));
	if (!path)
		return 0; //error malloc
	path->map_cpy = copy_map(data); //seg faults here
	printf("test\n");
	*path = find_p(data, *path);
	fill_path(path->map_cpy, path->x, path->y);
	
	int i = 0;
	while (i <= data.l_count)
	{
		printf("%s", path->map_cpy[i++]);
	}
	return 1;
}