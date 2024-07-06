#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
typedef struct Node
{
	int		collumns;
	int		rows;
	char	**map;
	int		map_fd;
	int		img_w;
	int		img_h;
	char	*bg_img_path;

}			t_map;

void		ft_allocate_map(t_map *map);
void		ft_get_measures(t_map *map);
void		ft_read_map(t_map *map);
#endif
