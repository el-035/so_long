#include "mlx.h"
#include"so_long.h"

#include<stdio.h>
typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;

}	t_mlx_data;

int	esc(int key, t_mlx_data *data)
{
	int x = 0;
	int y = 0;
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	if (key == 65362 || key == 119) //up
	{
		while (y < 699 && x < 699)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, 0x00FF0000);
			x++;
			y++;
		}
	}
	x = 0;
	y = 0;
	if (key == 65364 || key == 115) //down
	{
		while (y < 699 && x < 699)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, 0x00000000);
			x++;
			y++;
		}
	}
	/* if (key == 115)	//s
		mlx_put_image_to_window(data->mlx, data->window, data->image, 700, 250); */
		
	/* if (key == 65361 || key == 97)
		move left*/
	/*if (key == 65361 || key == 97)
		move left*/
	/*if (key == 65363 || key == 100)
		move right */
	printf("the key %d has been pressed \n", key); //delete
	return (0);
}

int	main(void)
{
	t_mlx_data data;
	//t_shroomie_data	shroom;
	char *filename = "./shroomie.xpm";
	int width;
	int height;
	data.mlx = mlx_init ();
	if (!data.mlx)
		return (0);
	data.window = mlx_new_window(data.mlx, 1300, 700, "so_long");
	if (!data.window)
		return (0);		//destroy window function, free stuff, return error
	
	mlx_key_hook(data.window, &esc, &data);
	data.image = mlx_xpm_file_to_image(data.mlx, filename, &width, &height);
	if (!data.image)
		return 0;
	mlx_put_image_to_window(data.mlx, data.window, data.image, 500, 500);

	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.image);
	//mlx_destroy_display(data.mlx);
	mlx_destroy_window(data.mlx, data.window);

	free(data.mlx);
	free(data.image);
	free(data.window);
	//exit(0);

	/* image = mlx_new_image(mlx, 1400, 700);
	if (!image)
		return 0; */
	/* data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	if (!data)
		return 0; */
	//mlx_get_color_value(mlx, 255);
	/* while (y < 699 && x < 699)
	{
		mlx_pixel_put(data.mlx, data.window, x, y, 0x00FF0000);
		x++;
		y++;
	} */

//	int	mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
	
	//mlx_put_image_to_window(mlx, window, image, 0, 0);
}

