#include <mlx.h>

int main (void)
{
  void *mlx_ptr;

  mlx_ptr = mlx_init ();
  mlx_new_window(mlx_ptr, 1000, 1000, "test");
}

mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );