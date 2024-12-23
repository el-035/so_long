/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:38:36 by efittant          #+#    #+#             */
/*   Updated: 2024/12/23 15:38:38 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(int fd, t_mlx data)
{
	char	*line;

	data.l_count = 0;
	line = get_next_line(fd);
	if (!line)
		errors("Allocation failed", data);
	while (line != NULL)
	{
		free(line);
		data.l_count++;
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (free (line), data.l_count);
}

char	**convert_map(int fd, t_mlx data)
{
	int	i;

	i = 0;
	data.map = (char **)malloc((data.l_count + 1) * sizeof(char *));
	if (!data.map)
		errors("Allocation failed", data);
	while (i < data.l_count)
	{
		data.map[i] = get_next_line(fd);
		if (!data.map[i])
		{
			while (i >= 0)
				free (data.map[--i]);
			free(data.map);
			errors("Allocation failed", data);
		}
		i++;
	}
	data.map[i] = NULL;
	get_next_line(-1);
	return (data.map);
}

void	validation(t_mlx data)
{
	line_len_check(data);
	wall_check_hor(data);
	char_check(data);
	more_char_check(data);
	wall_check_ver(data);
	path_validation(data);
	if (data.l_len > 40 || data.l_count > 20)
		errors("Map is too big", data);
}

int	line_len(t_mlx data)
{
	if (ft_strchr((const char *) data.map[0], '\n') == NULL)
		data.l_len = ft_strlen((const char *) data.map[0]);
	else
		data.l_len = ft_strlen((const char *) data.map[0]) - 1;
	return (data.l_len);
}

t_mlx	map(t_mlx data, char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		errors("Error opening map", data);
	data.l_count = line_count(fd, data);
	if (data.l_count == 0)
		print_err("Invalid map\n", data);
	close (fd);
	fd = open(map_file, O_RDONLY);
	data.map = convert_map(fd, data);
	if (!data.map)
	{
		close (fd);
		errors("Allocation failed", data);
	}
	data.l_len = line_len(data);
	validation(data);
	return (data);
}
