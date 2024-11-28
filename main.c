#include "mlx.h"
#include<stdlib.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*window;

	mlx_ptr = mlx_init ();
	window = mlx_new_window(mlx_ptr, 1000, 1000, "test");
	if (!window)
		return 0;
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, window);
}