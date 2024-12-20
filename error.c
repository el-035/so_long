#include"so_long.h"

void	print_err(char *error_msg, t_mlx data)
{
	ft_printf(error_msg);
	if(data.mlx)
		destroy_everything(&data);
	//exit (1);
}	

void	errors(char *error_msg, t_mlx data)
{
	perror (error_msg);
	if(data.mlx)
		destroy_everything(&data);
	exit (1);
}