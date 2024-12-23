/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:39:06 by efittant          #+#    #+#             */
/*   Updated: 2024/12/23 15:39:07 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_mlx data)
{
	char	**map_cpy;
	int		y;

	map_cpy = (char **) malloc(data.l_count * sizeof(char *));
	if (!map_cpy)
	{
		free(data.path);
		errors("Allocation failed", data);
	}
	y = 0;
	while (y < data.l_count)
	{
		map_cpy[y] = ft_strdup((const char *) data.map[y]);
		if (!map_cpy[y])
			errors("Allocation failed", data);
		y++;
	}
	return (map_cpy);
}

void	is_valid_path(t_mlx data, t_path *path)
{
	path->y = 0;
	while (path->y < data.l_count)
	{
		path->x = 0;
		while (path->x < data.l_len)
		{
			if (path->map_cpy[path->y][path->x] == 'C' || \
				path->map_cpy[path->y][path->x] == 'E')
			{
				free_copy(path, data);
				free(path);
				print_err("Invalid map\n", data);
			}
			path->x++;
		}
		path->y++;
	}
}

t_path	find_p(t_mlx data, t_path path)
{
	path.y = 0;
	while (path.y < data.l_count)
	{
		path.x = 0;
		while (path.x < data.l_len)
		{
			if (path.map_cpy[path.y][path.x] == 'P')
				return (path);
			path.x++;
		}
		path.y++;
	}
	return (path);
}

void	fill_path(t_mlx data, t_path path, int x, int y)
{
	if (y < 0 || x < 0 || y >= data.l_count || x >= data.l_len || \
			path.map_cpy[y][x] == '1' || path.map_cpy[y][x] == 'E')
	{
		if (path.map_cpy[y][x] == 'E')
			path.map_cpy[y][x] = '1';
		return ;
	}
	path.map_cpy[y][x] = '1';
	fill_path(data, path, x + 1, y);
	fill_path(data, path, x - 1, y);
	fill_path(data, path, x, y + 1);
	fill_path(data, path, x, y - 1);
}

void	path_validation(t_mlx data)
{
	t_path	*path;

	path = (t_path *) malloc(sizeof(t_path));
	if (!path)
		errors("Allocation failed", data);
	data.path = path;
	path->map_cpy = copy_map(data);
	*path = find_p(data, *path);
	fill_path(data, *path, path->x, path->y);
	is_valid_path(data, path);
	free_copy(path, data);
	free(path);
}
