/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:03:42 by asideris          #+#    #+#             */
/*   Updated: 2024/07/04 15:28:45 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <stdio.h>

void	ft_extract_map(void)
{
}
void	ft_fill_map(void *mlx_ptr, int win_width, int win_height,
		void *new_window)
{
	void	*bg_img;
	char	*bg_img_path;
	int		img_width;
	int		img_height;
	int		win_x;
	int		win_y;
	int		i;

	i = 0;
	win_x = 0;
	bg_img_path = "bg.xpm";
	bg_img = mlx_xpm_file_to_image(mlx_ptr, bg_img_path, &img_width,
			&img_height);
	while (win_x < win_width)
	{
		win_y = 0;
		while (win_y < win_height)
		{
			mlx_put_image_to_window(mlx_ptr, new_window, bg_img, win_x, win_y);
			win_y += img_height;
		}
		win_x += img_width;
	}
}
void	ft_map_size(t_map *map)
{
	int	fd;
	int	height;
	int	width;

	fd = open("map.ber", O_RDONLY);
	width = ft_strlen(get_next_line(fd));
	height = 1;
	while (1)
	{
		printf("ok");
		if (!get_next_line(fd))
			break ;
		height++;
	}
	printf("w : %d , h : %d", width, height);
	map->tile_x = width;
	map->tile_y = height;
}
int	main(void)
{
	void	*bg_img;
	char	*bg_img_path;
	void	*mlx_ptr;
	void	*new_window;
	int		bg_img_width;
	int		bg_img_height;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_map_size(map);
	mlx_ptr = mlx_init();
	bg_img_path = "bg.xpm";
	bg_img = mlx_xpm_file_to_image(mlx_ptr, bg_img_path, &bg_img_width,
			&bg_img_height);
	if (!mlx_ptr)
		return (0);
	new_window = mlx_new_window(mlx_ptr, (map->tile_x * bg_img_width),
			(map->tile_y * bg_img_height), "so_long");
	if (!new_window)
		return (0);
	ft_fill_map(mlx_ptr, (map->tile_x * bg_img_width), (map->tile_y
			* bg_img_height), new_window);
	mlx_loop(mlx_ptr);
	return (0);
}
