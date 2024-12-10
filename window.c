#include "mlx.h"
#include"so_long.h"

#include<stdio.h> //change printfs to ft_printf

/*
check that map ends in .ber and only 2 args
also check that all files can be opened such as the xpm for example, map etc
*/



void background_grass(t_mlx data)
{
	int width = 0;
    int height = 0;
    data.backgroung = mlx_xpm_file_to_image(data.mlx, "./images/background.xpm", &width, &height);

	while (height < 480)
	{
		width = 0;
		while(width < 1152)
        {
			mlx_put_image_to_window(data.mlx, data.window, data.backgroung, width, height);
            width += 48;
        }
        height += 48;
	}
}

int	main(void)
{
	t_mlx data;
	char *filename = "./obstacle.xpm";
	int width;
	int height;
	data.mlx = mlx_init ();
	if (!data.mlx)
		return (0);
	data.window = mlx_new_window(data.mlx, 1152, 480, "so_long"); //considering each block to be 48x48 itll be 24*12
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

