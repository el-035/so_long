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
void wall_check(char **map, int lc)
{

}

int	line_count_len_validation(int fd)	//result could be put in a struct
{
	int 	lc;
	size_t 	len;
	char	*line;
	
    lc = 0;
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen((const char*) line);
    while(line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;				//protection?
		if (ft_strlen((const char*) line) != len)		//it breaks if map.ber has no nl at the end
			return (0); 		//ERROR map not valid
		lc++;
	}
    return (lc);
}

char **convert_map(int fd, int lc) //before calling this fd must be closed and opened again
{
	char	**map;
	char	*line;
	int		i;
	
	i = 0;
	map = (char**)malloc(lc * sizeof(char *));
	if (!map)
		return (NULL);
	while(i <= lc)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		map[i] = ft_strdup(line);		//ft_strdup
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

char **map()	//takes argv[1]
{
	char	**map;
	int		fd;
	int		lc;
	fd = open("map.ber", O_RDONLY);	//map is the parameter
	//fd check
	lc = line_count_len_validation(fd);
	if (lc == 0)
		return (NULL);					//handle error
	close (fd);
	fd = open("map.ber", O_RDONLY);		//map is the parameter
	map = convert_map(fd, lc);
	if (!map)
		return (NULL);
	// validate map function

	return (map);
}

int main ()
{
	map();
}