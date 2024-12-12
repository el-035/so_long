#include"so_long.h"
t_map map_main (char *map_file)
{
	t_map *data;
	data = (t_map *) malloc(sizeof(t_map));
	if (!data)
		exit (1); //error malloc
	map(data);
	if(!data->map)
		exit (1);
	
	return (*data);
}

int main (int argc, char **argv)	//take map as arg
{
	if (argc != 2)
		return (0);		//error
	//check that all files that need to be opened can be opened
		//all xpm
		//all maps
	//check map files end in ber aka argv 1
	//initialise all structs   
	//validate map						ok
	//open window						ok
		//create image of background	ok
		//create events					ok
			//moving 4 directions		ok
			//esc						ok
			//x button to close
			//parse the map
	//destroy everything
	map_main (argv[1]);
	window_main ();

}
