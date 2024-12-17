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
	int		l_count;
	int		l_len;
	void	*shroom_image;
	void 	*backgroung;
	void	*obstacle;
	void	*end_closed;
	void	*end_open;
	void	*collectible;
	int		tile_width;
	int		tile_height;
	int		moves;
	int		x_char;
	int		y_char;
	int		x_end;
	int		y_end;
	int		collectible_count;
	int		c_flag;
}			t_mlx;


//all function prototypes
//main
void	map_input(char *map_file);

//window
t_mlx	initialise_stuff(t_mlx data);
void	background_grass(t_mlx data);
t_mlx   save_images(t_mlx data);

//events
int		events(int key, t_mlx *data);
void	move_left(t_mlx *data);
void	move_right(t_mlx *data);
void	move_down(t_mlx *data);
void	move_up(t_mlx *data);

//map
t_mlx	map(t_mlx data, char *map_file);
int 	line_len(t_mlx data);
void	validation(t_mlx data);
char 	**convert_map(int fd, t_mlx data);
int		line_count(int fd, t_mlx data);

//map validation
void	wall_check_hor(t_mlx data);
void	wall_check_ver(t_mlx data);
void	char_check(t_mlx data);
void	line_len_check(t_mlx data);
void	more_char_check(t_mlx data);


//path validation
char	**copy_map(t_mlx data);
t_path	find_p(t_mlx data, t_path path);
void	fill_path(t_mlx data, t_path path, int x, int y);
void	path_validation(t_mlx data);
void	is_valid_path(t_mlx data, t_path path);

//map parsing
void	map_parsing(t_mlx *data);
void	char_location(t_mlx *data, int x, int y);
void	end_location(t_mlx *data, int x, int y);
void	parsing_conditions(t_mlx *data, int x, int y);

//game rules
void	collectibles(t_mlx *data, int x, int y);
void	end_of_game(t_mlx *data);
//int		close_everything(t_mlx *data);

//error
void	errors(char *error_msg, t_mlx data);
void	print_err(char *error_msg, t_mlx data);

//free
void	free_copy(t_path *map, t_mlx data);
void	free_map(char **map);
int	destroy_everything(t_mlx data);

#endif