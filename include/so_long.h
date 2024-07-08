#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
typedef struct Node
{
	void	*bg_img;
	void	*obstacle_1;
	void	*char_img;
	void	*wall;
	void	*flowers;

	int		collumns;
	int		rows;

	char	**map;

	int		map_fd;
	void	*mlx_ptr;
	int		tile_w;
	int		tile_h;
	void	*window_ptr;

	int		player_pos_y;
	int		player_pos_x;
	int		score;

}			t_map;
int			ft_check_walls(t_map *map);
void		ft_allocate_map(t_map *map);
void		ft_get_measures(t_map *map);
void		ft_read_map(t_map *map);
void		ft_setup_struct(t_map *map);
char		*ft_itoa(int n);
void		ft_populate_map(t_map *map);
void		ft_format(t_map *map);
int			ft_move(int keycode, void *param);
int			ft_check_rows(t_map *map);

#endif
