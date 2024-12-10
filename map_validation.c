#include"so_long.h"
#include "libft.h"  
#include <stdio.h>	//delete
//validate map
	//only valid charachters								/done to test
    //all lines same len									/done
    //walls around											/done to test
    //valid path (flood fill??) to exit and collectibles

int	line_len_check(t_map data)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while(i < data.l_count)
	{
		if (ft_strchr((const char *) data.map[i], '\n') == NULL)
			len = ft_strlen((const char *) data.map[i]);
		else
			len = ft_strlen((const char *) data.map[i]) - 1;
		if (len != data.l_len)
			return (0);
		i++;
	}
	return (1);
}

int wall_check_hor(t_map data)	//	chnage to void and put error 
{
	int	j;

	j = 0;
	while (data.map[0][j] && data.map[0][j] != '\n')
	{
		if (data.map[0][j] != '1')
			return 0;
		j++;
	}
	j = 0;
	while (data.map[data.l_count - 1][j] && data.map[data.l_count - 1][j] != '\n')
	{
		if (data.map[data.l_count - 1][j] != '1')
			return 0;
		j++;
	}
	return 1;
}

int wall_check_ver(t_map data)	//	chnage to void and put error 
{
	int	i;

	i = 0;
	while (i < data.l_count)
	{
		if (data.map[i][0] != '1')
			return 0;
		i++;
	}
	i = 0;
	while (i < data.l_count)
	{
		if (data.map[i][data.l_len - 1] != '1')
			return 0;
		i++;
	}
	return 1;
}

int	char_check(t_map data)	//	chnage to void and put error 
{
	int	i;
	int	j;
    int p;

	i = 0;
    p = 0;
	while(i < data.l_count)
	{
		j = 0;
        while (data.map[i][j] && data.map[i][j] != '\n')
		{
			if (data.map[i][j] != '1' && data.map[i][j] != '0' && data.map[i][j] != 'P' && data.map[i][j] != 'C' && data.map[i][j] != 'E')
				return (0);
            if (data.map[i][j] == 'P')
                p++;
			j++;
		}
		i++;
	}
    if (p != 1)
        return (0);
    else
	    return (1);
}

int more_char_check(t_map data)
{
	int	i;
	int	j;
    int c;
    int e;

	i = 0;
    c = 0;
    e = 0;
	while(i < data.l_count)
	{
		j = 0;
        while (data.map[i][j] && data.map[i][j] != '\n')
		{
			if (data.map[i][j] == 'E')
                e++;
            if (data.map[i][j] == 'C')
                c++;
			j++;
		}
		i++;
	}
    if (e != 1 || c < 1)
        return (0);
    else
	    return (1);
}
