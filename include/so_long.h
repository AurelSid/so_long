#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct Node
{
	int		tile_x;
	int		tile_y;
	char	**map;
}			t_map;
#endif
