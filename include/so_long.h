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
	void	*exit_img;
	void	*wall;
	void	*flowers;

	int		collumns;
	int		rows;
	int		tokens;
	int		p_count;
	int		exit_c;

	char	**map;
	char	**map_copy;

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
void		ft_read_map(t_map *map, char *file_name);
void		ft_setup_struct(t_map *map);
char		*ft_itoa(int n);
void		ft_populate_map(t_map *map);
void		ft_format(t_map *map);
int			ft_move(int keycode, void *param);
int			ft_check_rows(t_map *map);
int			ft_check_valid_tile(t_map *map);
int			ft_backtrack(t_map *map, int x, int y);
int			ft_token_count(t_map *map);
void		ft_exit_free(t_map *map, char *error);
void		ft_printf_map(t_map *map);

#endif
