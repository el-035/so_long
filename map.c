#include"so_long.h"
#include <stdio.h>
//first get number of lines (close and open file again)		/done
//convert map into a 2d array								/done
	//remove nl at the end of each line						necessary?? would help fix the issue when map has no nl at the end
//validate map
	//only valid charachters
	//all lines same len									/done
	//walls around
	//valid path (flood fill??)

int	line_count(int fd, t_mlx data)	
{
	char	*line;
	
	data.l_count = 0;
	line = get_next_line(fd);
	if (!line)
		errors("Allocation failed");
	while(line != NULL)
	{
		free(line);
		data.l_count++;
		line = get_next_line(fd);
		if (!line)
			break ;			//???
	}
	return (free (line), data.l_count);
}
/* int	line_count(int fd)
{
	int lc;

    lc = 0;
	while(get_next_line(fd) != NULL)
		lc++;
	return (lc);
} */

char **convert_map(int fd, t_mlx data)
{
	int	i;

	i = 0;
	data.map = (char**)malloc((data.l_count + 1) * sizeof(char *));
	if (!data.map)
		errors("Allocation failed");
	while(i < data.l_count)
	{
		data.map[i] = get_next_line(fd);
		if (!data.map[i])
		{           
			while (i >= 0)
				free (data.map[--i]);
			free(data.map);
			errors("Allocation failed");
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
}
int line_len(t_mlx data)
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
        errors("Error opening map");
	data.l_count = line_count(fd, data);
	if (data.l_count == 0)
		print_err("Invalid map\n");					//???
	close (fd);
	fd = open(map_file, O_RDONLY);
	data.map = convert_map(fd, data);
	if (!data.map)
	{
		close (fd);
		free_map(data.map);
		errors("Allocation failed");
	}
	data.l_len = line_len(data);
	validation(data);
	return (data);
}
