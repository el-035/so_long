#include"so_long.h"

void    move_up(t_mlx *data)
{
    mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->tile_width, data->tile_height);
	ft_printf("moves: %d\n", data->moves++);
	data->tile_height = data->tile_height - 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->tile_width, data->tile_height);
}
void    move_down(t_mlx *data)
{
    mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->tile_width, data->tile_height);
	ft_printf("moves: %d\n", data->moves++);
	data->tile_height = data->tile_height + 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->tile_width, data->tile_height);
}

void    move_right(t_mlx *data)
{
    mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->tile_width, data->tile_height);
	ft_printf("moves: %d\n", data->moves++);	
	data->tile_width = data->tile_width + 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->tile_width, data->tile_height);
}

void    move_left(t_mlx *data)
{
    mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->tile_width, data->tile_height);
	ft_printf("moves: %d\n", data->moves++);
	data->tile_width = data->tile_width - 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->tile_width, data->tile_height);
}

int events(int key, t_mlx *data)
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
        move_right(data);
	if (key == 65364 || key == 115) //down
		move_down(data);
	if (key == 65362 || key == 119) //up
		move_up(data);
	if (key == 65361 || key == 97) //left
		move_left(data);
	return (0);
}