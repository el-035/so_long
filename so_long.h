#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char	**map;
	int		l_count;
	int		l_len;
}	t_map;

typedef struct s_path
{
	char	**map_cpy;
	int		y;
	int		x;
}	t_path;

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
int more_char_check(t_map data);
//path validation
char	**copy_map(t_map data);
t_path	find_p(t_map data, t_path path);
void	fill_path(t_map data, t_path path, int x, int y);
int	path_validation(t_map data);
int is_valid_path(t_map data, t_path path);

#endif