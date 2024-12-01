#include "mlx.h"
#include"so_long.h"
//#include "libft.h"

#include<string.h>          //to delete

int validate_map(char **map)
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

}

char **convert_map()
{
    char **map;
    int i = 0;
    int lc = 0;
    int fd = open("map.ber", O_RDONLY);
    
    while(get_next_line(fd) != NULL)
        lc++;
    map = (char**)malloc((lc + 1)*sizeof(char*));
    if (!map)
        return NULL;
    close(fd);
    fd = open("map.ber", O_RDONLY);
    while (i <= lc)
    {
        map[i] = strdup(get_next_line(fd));      //change to ft_
        if (!map[i++])
            return (NULL);
    }
    map[i] = strdup("\0");
    if (!map[i])                //makes no sense 
            return (NULL);
    if (validate_map(map) == 1)
        return (map);
    else
        return (NULL)       //error message
}
