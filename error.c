#include"so_long.h"

//malloc error			  perror

//If any misconfiguration of any kind is encountered in the file, the program must
//exit in a clean way, and return "Error\n" followed by an explicit error message of
//your choice.

void	print_err(char *error_msg)
{
	ft_printf(error_msg);
	exit (1);
}	
/* if (flag == 2)
		print_err("Invalid input, please use a .ber file\n");
	if (flag == 3)
		print_err("Invalid map\n"); */


void	errors(char *error_msg)
{
	perror (error_msg);
	
	/* if (flag == 0)
		errors("Error opening images");
	if (flag == 1)
		errors("Error opening map");
	
	
	if (flag == 4)
		errors("Invalid number of arguments");
	if (flag == 5)
		errors("Allocation failed");
 */
	
	exit (1);
}