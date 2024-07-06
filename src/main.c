

#include "../include/so_long.h"

int	main(void)
{
	void	*bg_img;
	char	*bg_img_path;
	void	*mlx_ptr;
	int		bg_img_width;
	int		bg_img_height;
	t_map	*map;
	void	*new_window;

	map = (t_map *)malloc(sizeof(t_map));
	ft_get_measures(map);
	ft_read_map(map);
	mlx_ptr = mlx_init();
	bg_img_path = "bg.xpm";
	map->map_fd = open("map.ber", O_RDONLY);
	bg_img = mlx_xpm_file_to_image(mlx_ptr, bg_img_path, &bg_img_width,
			&bg_img_height);
	if (!mlx_ptr)
		return (0);
	new_window = mlx_new_window(mlx_ptr, (map->collumns * bg_img_width),
			(map->rows * bg_img_height), "so_long");
	if (!new_window)
		return (0);
	mlx_loop(mlx_ptr);
	return (0);
}

// ft_setup_struct(t_map *map)
// {

// }
