#include"so_long.h"

void    collectibles(t_mlx *data, int x, int y)
{
    data->map[y][x] = '0';
    data->collectible_count--;
    
    if (data->collectible_count == 0)
        mlx_put_image_to_window(data->mlx, data->window, data->end_open, data->x_end, data->y_end);
}

void    end_of_game(t_mlx *data)
{
    if (data->collectible_count == 0)
        return ;
    else
        return ;
}
/* void    close_everything(t_mlx *data)
{

} */