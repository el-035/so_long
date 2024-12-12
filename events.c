#include"so_long.h"
#include<stdio.h>
void    move_up(t_mlx *data, t_map map_data)
{
	int y;
	int x;
	y = (data->y_char / 48) - 1;
	x = data->x_char / 48;
	write(1, &map_data.map[y][x], 1);
	write(1, "\n", 1);
	write(1, &map_data.map[4][9], 1);
	write(1, "\n", 1);
	printf("x:%d\n", x);
	printf("y:%d\n", y);
	if (map_data.map[y][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);
	data->y_char = data->y_char - 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}
void    move_down(t_mlx *data/*,  t_map map_data */)
{
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	data->y_char = data->y_char + 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

void    move_right(t_mlx *data/* , t_map map_data */)
{
    
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);	
	data->x_char = data->x_char + 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

void    move_left(t_mlx *data/* , t_map map_data */)
{
    
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);
	data->x_char = data->x_char - 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

int events(int key, t_mlx *data, t_map map_data)
{
	if (key == 65307) //pls same thing if tab is closed
	{
		ft_printf("moves: %d\n", data->moves++);			//to change to ft_print
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx); //???
		free(data->mlx);
		exit(0);
	}
	if (key == 65363 || key == 100) //right
        move_right(data/*,  map_data */);
	if (key == 65364 || key == 115) //down
		move_down(data/*,  map_data */);
	if (key == 65362 || key == 119) //up
		move_up(data, map_data);
	if (key == 65361 || key == 97) //left
		move_left(data/*,  map_data */);
	return (0);
}