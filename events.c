#include "mlx.h"
#include"so_long.h"
#include<stdio.h> //change printfs to ft_printf

int esc(int key, t_mlx *data)
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
	if (key == 65362 || key == 119) //up
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
		height = height - 48;
		mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, width, height);
	}
	//printf("moves: %d\n", key);
	
	if (key == 65361 || key == 97)
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
		width = width - 48;
		mlx_put_image_to_window(data->mlx, data->window, data->shroom_image, width, height);
	} 


	/*if (key == 65361 || key == 97)
		move left*/
	/*if (key == 65363 || key == 100)
		move right */
	
	//printf("%d\n",key); //delete
	return (0);
}