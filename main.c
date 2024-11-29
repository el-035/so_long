#include "mlx.h"
#include"so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
	int 	endian;
	int		x = 0;
	int 	y = 0;

	mlx = mlx_init ();
	window = mlx_new_window(mlx, 1300, 700, "test");
	if (!window)
		return 0;
	image = mlx_new_image(mlx, 1300, 700);
	if (!image)
		return 0;
	data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	if (!data)
		return 0;
	//mlx_get_color_value(mlx, 255);
	while (y < 700 && x < 700)
	{
		mlx_pixel_put(mlx, window, x, y, 0x00FF0000);
		x++;
		y++;
	}
	y--;
	x--;
	while (y < 1300)
	{
		mlx_pixel_put(mlx, window, x, y, 0x0000FFFF);
		x--;
		y++;
	}
	

	//mlx_put_image_to_window(mlx, window, image, 0, 0);
	mlx_loop(mlx);
	//mlx_destroy_window(mlx_ptr, window);
}