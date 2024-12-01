#include "mlx.h"
#include"so_long.h"

#include<stdio.h> //change printfs to ft_printf
typedef struct s_data
{
	void	*mlx;
	void	*window;
	/* int		wind_x; 	make variables for window size
	int		wind_y; */
	void	*shroom_image;
	void 	*backgroung_image;

}	t_mlx_data;

int	esc(int key, t_mlx_data *data)
{
	/* int x = 0;
	int y = 0; */
	static int width = 48;
	static int height = 48;
	static int moves = 1;
	int x = width;
	int y = height;
	int xtemp = x + 48;
	int ytemp = y + 48;
	if (key == 65307) //pls same thing if tab is closed
	{
		printf("moves: %d\n", moves++);			//to change to ft_print
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx); //???
		free(data->mlx);
		exit(0);
	}
	/* if (key == 115)	//s
		mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, width, height); */

	if (key == 65363 || key == 100) //right
	{
		xtemp = x + 48;
		ytemp = y + 48;
		while (y <= ytemp)
		{
			x = 0;
			while(x <= xtemp)
				mlx_pixel_put(data->mlx, data->window, x++, y, 0xFF9CDB43);
			y++;
		}
		printf("moves: %d\n", moves++);	
		width = width + 48;
		mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, width, height);
	}
	if (key == 65364 || key == 115) //down
	{
		xtemp = x + 48;
		ytemp = y + 48;
		while (y <= ytemp)
		{
			x = 0;
			while(x <= xtemp)
				mlx_pixel_put(data->mlx, data->window, x++, y, 0xFF9CDB43);
			y++;
		}
		printf("moves: %d\n", moves++);
		height = height + 48;
		mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, width, height);
	}
	/* if (key == 65362 || key == 119) //up
	{
		printf("moves: %d\n", moves++);
		while (y < 699 && x < 699)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, 0x00FF0000);
			x++;
			y++;
		}
	} 
	x = 0;
	y = 0;
	
	}*/


	/* if (key == 65361 || key == 97)
		move left*/
	/*if (key == 65361 || key == 97)
		move left*/
	/*if (key == 65363 || key == 100)
		move right */
	
	//printf("%d\n",key); //delete
	return (0);
}

void background_grass(t_mlx_data data)
{
	int x = 0;
	int y = 0;
	while (y <= 800)
	{
		x = 0;
		while(x <= 1200)
			mlx_pixel_put(data.mlx, data.window, x++, y, 0xFF9CDB43);
		y++;
	}
}

int	main(void)
{
	t_mlx_data data;
	char *filename = "./shroomie.xpm";
	int width;
	int height;
	data.mlx = mlx_init ();
	if (!data.mlx)
		return (0);
	data.window = mlx_new_window(data.mlx, 1200, 800, "so_long"); //considering each block to be 48x48 itll be 24*12
	if (!data.window)
		return (0);		//destroy window function, free stuff, return error
	
	//to put background
	background_grass(data);

	//to get key response
	mlx_key_hook(data.window, &esc, &data);
	
	//to put the shroom
	data.shroom_image = mlx_xpm_file_to_image(data.mlx, filename, &width, &height);
	if (!data.shroom_image)
		return 0;
	//mlx_put_image_to_window(data.mlx, data.window, data.shroom_image, 100, 100);
	
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.shroom_image);
	mlx_destroy_window(data.mlx, data.window);
	//mlx_destroy_display(data.mlx);
	free(data.mlx);
	free(data.shroom_image);
	free(data.window);
	//exit(0);
}

