//#include "mlx.h"
#include"so_long.h"
//#include "libft.h"  //add files in the folder
#include "get_next_line.h"

#include<string.h>          //to delete
#include <stdio.h>
/* int validate_map(char **map)
{
    int len = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while(map[i])
    {
        while(map[i][len])
            len++;
        
        if (len != 0)
        {
            if (len != count)
                return 0;
        }
    }

} */

char **convert_map(int fd, int lc)
{
    char **map;
    int i = 0;
    
    while (i <= lc)
    {
        map[i] = strdup(get_next_line(fd));      //change to ft_
        if (!map[i++])
            return (NULL);
    }
    map[i] = strdup("\0");
    if (!map[i])                //makes no sense 
            return (NULL);
    //if (validate_map(map) == 1)
    return (map);
    /* else
        return (NULL); */    //error message
}
int main ()
{
    
    int lc = 0;
    int fd = open("map.ber", O_RDONLY);
    
    while(get_next_line(fd) != NULL)
        lc++;
    map = (char**)malloc((lc + 1)*sizeof(char*));
    if (!map)
        return NULL;
    close(fd);
    fd = open("map.ber", O_RDONLY);
    int i = 0;
    char **map = convert_map(fd, lc);
    while(map[i])
    {
        printf("%s\n", map[i++]);
    }
}