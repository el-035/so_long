#include"so_long.h"

//malloc error			  perror

//If any misconfiguration of any kind is encountered in the file, the program must
//exit in a clean way, and return "Error\n" followed by an explicit error message of
//your choice.

void	print_err(char *error_msg, t_mlx data)
{
	ft_printf(error_msg);
	destroy_everything(data);
	exit (1);
}	

void	errors(char *error_msg, t_mlx data)
{
	perror (error_msg);
	destroy_everything(data);
	exit (1);
}