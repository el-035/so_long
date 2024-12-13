#include"so_long.h"

void    move_up(t_mlx *data)
{
	int y;
    int x;

    y = (data->y_char / 48) - 1;
    x = data->x_char / 48;
    if (data->map[y][x] == 'C')
        collectibles(data, x, y);
    if (data->map[y][x] == 'E')
		return (end_of_game(data));
    if (data->map[y][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);
	data->y_char = data->y_char - 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

void    move_down(t_mlx *data)
{
	int y;
    int x;

    y = (data->y_char / 48) + 1;
    x = data->x_char / 48;
    if (data->map[y][x] == 'C')
        collectibles(data, x, y);
    if (data->map[y][x] == 'E')
		return (end_of_game(data));
    if (data->map[y][x] == '1')
		return ;
    mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);
    data->y_char = data->y_char + 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

void    move_right(t_mlx *data)
{
    int y;
    int x;

    y = data->y_char / 48;
    x = (data->x_char / 48) + 1;
    if (data->map[y][x] == 'C')
        collectibles(data, x, y);
    if (data->map[y][x] == 'E')
		return (end_of_game(data));
    if (data->map[y][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);	
	data->x_char = data->x_char + 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

void    move_left(t_mlx *data)
{
    int y;
    int x;

    y = data->y_char / 48;
    x = (data->x_char / 48) - 1;
    if (data->map[y][x] == 'C')
        collectibles(data, x, y);
    if (data->map[y][x] == 'E')
		return (end_of_game(data));
    if (data->map[y][x] == '1')
		return ;
	mlx_put_image_to_window(data->mlx, data->window, data->backgroung, data->x_char, data->y_char);
	ft_printf("moves: %d\n", data->moves++);
	data->x_char = data->x_char - 48;
	mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, data->x_char, data->y_char);
}

int events(int key, t_mlx *data)
{

    if (key == 65307) //pls same thing if tab is closed
	{
		ft_printf("moves: %d\n", data->moves++);
        mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx); //???
		free(data->mlx);
		exit(0);
	}
	if (key == 65363 || key == 100)
        move_right(data);
	if (key == 65364 || key == 115)
		move_down(data);
	if (key == 65362 || key == 119)
		move_up(data);
	if (key == 65361 || key == 97)
		move_left(data);
	return (0);
}
