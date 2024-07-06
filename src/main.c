

#include "../include/so_long.h"

int	main(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_setup_struct(map);
	ft_get_measures(map);
	ft_read_map(map);
	map->window_ptr = mlx_new_window(map->mlx_ptr, (map->collumns
				* map->bg_img_width), (map->rows * map->bg_img_height),
			"so_long");
	if (!map->mlx_ptr)
		return (0);
	if (!map->window_ptr)
		return (0);
	ft_populate_map(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}

void	ft_setup_struct(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return ;
	map->bg_img = mlx_xpm_file_to_image(map->mlx_ptr, "bg.xpm",
			&map->bg_img_width, &map->bg_img_height);
	map->char_img= mlx_xpm_file_to_image(map->mlx_ptr, "static_char.xpm",
			&map->bg_img_width, &map->bg_img_height);
	if (!map->bg_img)
		return ;
}
