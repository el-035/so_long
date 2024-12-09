#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char	**map;
	int		l_count;
	int		l_len;
}	t_map;


//all stuff to include
#include <stdlib.h>
//#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

//all function prototypes



//map validation
int wall_check_hor(t_map data);
int wall_check_ver(t_map data);
int	char_check(t_map data);
int	line_len_check(t_map data);
#endif