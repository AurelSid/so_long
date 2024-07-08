

#include "../include/so_long.h"

void	ft_setup_struct(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return ;
	map->bg_img = mlx_xpm_file_to_image(map->mlx_ptr, "bg.xpm", &map->tile_w,
			&map->tile_h);
	map->obstacle_1 = mlx_xpm_file_to_image(map->mlx_ptr, "obstacle_1.xpm",
			&map->tile_w, &map->tile_h);
	map->char_img = mlx_xpm_file_to_image(map->mlx_ptr, "static_char.xpm",
			&map->tile_w, &map->tile_h);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, "wall.xpm", &map->tile_w,
			&map->tile_h);
	map->flowers = mlx_xpm_file_to_image(map->mlx_ptr, "blue_flowers.xpm",
			&map->tile_w, &map->tile_h);
	map->score = 0;
}

void	ft_set_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->collumns)
		{
			if (map->map[i][j] == 'C')
			{
				map->player_pos_x = j;
				map->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_setup_struct(map);
	ft_read_map(map);
	if (!ft_check_walls(map))
		return (0);
	if (!ft_check_rows(map))
		return (0);
	map->window_ptr = mlx_new_window(map->mlx_ptr, (map->collumns
				* map->tile_w), (map->rows * map->tile_h), "so_long");
	if (!map->mlx_ptr)
		return (0);
	if (!map->window_ptr)
		return (0);
	ft_populate_map(map);
	mlx_key_hook(map->window_ptr, ft_move, map);
	ft_set_player_pos(map);
	mlx_string_put(map->mlx_ptr, map->window_ptr, 20, 0, 0xFFFFFF, "SCORE: ");
	mlx_string_put(map->mlx_ptr, map->window_ptr, 60 + 20, 0, 0xFFFFFF,
		ft_itoa(map->score));
	mlx_loop(map->mlx_ptr);
	return (0);
}
