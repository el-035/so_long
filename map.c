//#include "mlx.h"
#include"so_long.h"
#include "libft.h"  //add files in the folder
#include "get_next_line.h"

#include<string.h>          //to delete
#include <stdio.h>

//first get number of lines (close and open file again)		/done
//convert map into a 2d array								/done
    //remove nl at the end of each line						necessary?? would help fix the issue when map has no nl at the end
//validate map
	//only valid charachters
    //all lines same len									/done
    //walls around
    //valid path (flood fill??)


int	line_count(int fd, t_map data)	//result could be put in a struct
{
	char	*line;
	
    data.l_count = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);		//error
    while(line != NULL)
	{
		data.l_count++;
		line = get_next_line(fd);
		if (!line)
			break ;				//protection?
	}
	return (data.l_count);
}

char **convert_map(int fd, t_map data) //before calling this fd must be closed and opened again
{
	int	i;

	i = 0;
	data.map = (char**)malloc((data.l_count) * sizeof(char *));
	if (!data.map)
		return (NULL);
	while(i <= data.l_count)
	{
		data.map[i] = get_next_line(fd);
		if (!data.map[i])
			break;
		i++;
	}
	return (data.map);
}

int	validation(t_map data)
{
	if (line_len_check(data) == 0)
		return (0); //Error message invalid map
	if (wall_check_hor(data) == 0)
		return (0); //Error message invalid map
	if (char_check(data) == 0)                      //also check that E and P only appear once
		return (0); //Error message invalid map
	if (wall_check_ver(data) == 0)
		return (0); //Error message invalid map

    //call path validation
    //valid_path(data);
}
int line_len(t_map data)
{
	if (ft_strchr((const char *) data.map[0], '\n') == NULL)
		data.l_len = ft_strlen((const char *) data.map[0]);
	else
		data.l_len = ft_strlen((const char *) data.map[0]) - 1;
	printf("len:%d\n", data.l_len);
	return (data.l_len);
}

char **map(t_map data)	//takes argv[1]
{
	int		fd;

	fd = open("map.ber", O_RDONLY);	//map is the parameter
	if (fd <= 0)
		return NULL;		//handle error
	data.l_count = line_count(fd, data);
	if (data.l_count == 0)
		return (NULL);					//handle error
	close (fd);
	fd = open("map.ber", O_RDONLY);		//map is the parameter
	data.map = convert_map(fd, data);
	if (!data.map)
		return (NULL);
	data.l_len = line_len(data);
	validation(data);
	return (data.map);
}

int main ()
{
	t_map *data;
	data = (t_map *) malloc(sizeof(t_map));
	if (!data)
		return 0; //error malloc
	data->map = map(*data);
	if(!data->map)
		return 0;
}