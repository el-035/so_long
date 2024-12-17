# ifndef SO_LONG_H
# define SO_LONG_H

//all stuff to include
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <mlx.h>
//#include "minilibx-linux/mlx.h" //delete and put the previous one
#include <math.h>			   //never used
#include <unistd.h>
#include <fcntl.h>		  //??
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**map;
	int		l_count;
	int		l_len;
}			t_map;

typedef struct s_path
{
	char	**map_cpy;
	int		y;
	int		x;
}			t_path;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	char	**map;
	void	*shroom_image;
	void 	*backgroung;
	void	*obstacle;
	void	*end_closed;
	void	*end_open;
	void	*collectible;
	int  tile_width;
	int  tile_height;
	int  moves;
	int  x_char;
	int  y_char;
	int  x_end;
	int  y_end;
	int  collectible_count;
	int  c_flag;
}		t_mlx;


//all function prototypes
//window
void	window_main(char *map_file);
t_mlx	initialise_stuff(t_mlx data, t_map map_data);
void	background_grass(t_mlx data, t_map map_data);
t_mlx   save_images(t_mlx data, t_map *map);

//events
int		events(int key, t_mlx *data);
void	move_left(t_mlx *data);
void	move_right(t_mlx *data);
void	move_down(t_mlx *data);
void	move_up(t_mlx *data);

//map validation
void	wall_check_hor(t_map data);
void	wall_check_ver(t_map data);
void	char_check(t_map data);
void	line_len_check(t_map data);
void	more_char_check(t_map data);
void	map(t_map *data, char *map_file);

//path validation
char	**copy_map(t_map data);
t_path	find_p(t_map data, t_path path);
void	fill_path(t_map data, t_path path, int x, int y);
void		path_validation(t_map data);
void		is_valid_path(t_map data, t_path path);

//map parsing
void	map_parsing(t_map map_data, t_mlx *mlx_data);
void	char_location(t_mlx *data, int x, int y);

//main
t_map   *map_main (char *map_file);
void	map_input(char *map_file);
//int	open_window(void);

//game rules
void	collectibles(t_mlx *data, int x, int y);
void	end_of_game(t_mlx *data);
void	close_everything(t_mlx *data);

//error
void	errors(char *error_msg);
void	print_err(char *error_msg);

//free
void	free_copy(t_path *map, t_map data);
void	free_map(t_map *map);
void	destroy_everything(t_mlx data, t_map *map);

#endif