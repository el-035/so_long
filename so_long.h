# ifndef SO_LONG_H
# define SO_LONG_H

//all stuff to include
#include <stdlib.h>
//#include <mlx.h>
#include "mlx.h"    //delete and put the previous one
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include "ft_printf.h"


typedef struct s_map
{
	char	**map;
	int		l_count;
	int		l_len;
    int     collectible_count;
}	t_map;

typedef struct s_path
{
	char	**map_cpy;
	int		y;
	int		x;
}	t_path;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		wind_x;
	int		wind_y;
	void	*shroom_image;
	void 	*backgroung;
    void    *obstacle;
    void    *end_closed;
    void    *end_open;
    void    *collectible;
    int     tile_width;
    int     tile_height;
    int     moves;

}	t_mlx;



//all function prototypes
//window
void window_main(void);
t_mlx	initialise_stuff(t_mlx data);
void background_grass(t_mlx data);
t_mlx   save_images(t_mlx data);

//events
int     events(int key, t_mlx *data);
void    move_left(t_mlx *data);
void    move_right(t_mlx *data);
void    move_down(t_mlx *data);
void    move_up(t_mlx *data);

//map validation
int	wall_check_hor(t_map data);
int	wall_check_ver(t_map data);
int	char_check(t_map data);
int	line_len_check(t_map data);
int	more_char_check(t_map data);

//path validation
char	**copy_map(t_map data);
t_path	find_p(t_map data, t_path path);
void	fill_path(t_map data, t_path path, int x, int y);
int		path_validation(t_map data);
int		is_valid_path(t_map data, t_path path);

//map parsing
void map_parsing(t_map map_data, t_mlx mlx_data);


//to delete later
t_map beginning ();
//int	open_window(void);

#endif