//validate map
	//only valid charachters								/done to test
    //all lines same len									/done
    //walls around											/done to test
    //valid path (flood fill??)

int wall_check_hor(char **map, int lc)	//	chnage to void and put error 
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return 0;
		j++;
	}
	j = 0;
	while (map[lc][j] != '\n')
	{
		if (map[lc][j] != '1')
			return 0;
		j++;
	}
	return 1;
}

int wall_check_ver(char **map, int lc)	//	chnage to void and put error 
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((const char *) map[i]) - 1;
	while (i <= lc)
	{
		if (map[i][0] != '1')
			return 0;
		i++;
	}
	i = 0;
	while (i <= lc)
	{
		if (map[i][len] != '1')
			return 0;
		i++;
	}
	return 1;
}

int	char_check(char **map, int lc)	//	chnage to void and put error 
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i <= lc)
	{
		while (map[i][j] != '\n')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

