/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:03:42 by asideris          #+#    #+#             */
/*   Updated: 2024/07/06 12:06:07 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_get_measures(t_map *map)
{
	int		fd;
	char	*str;

	map->collumns = 0;
	map->rows = 0;
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			break ;
		}
		map->collumns = ft_strlen(str);
		map->rows++;
	}
}
void	ft_allocate_map(t_map *map)
{
	int	i;
	int	j;

	map->map = (char **)malloc(map->rows * sizeof(char *));
	i = 0;
	while (i < map->rows)
	{
		map->map[i] = (char *)malloc(map->collumns * sizeof(char));
		if (map->map[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(map->map[j]);
				j++;
			}
			free(map->map);
		}
		i++;
	}
}

void	ft_read_map(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	ft_allocate_map(map);
	fd = open("map.ber", O_RDONLY);
	i = 0;
	while (i < map->rows)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		ft_strlcpy(map->map[i], line, map->collumns);
		free(line);
		i++;
	}
	close(fd);
}

// void	ft_populate_map(t_map *map);
// {
// 	void *bg_img;
// 	char *bg_img_path;
// 	int img_width;
// 	int img_height;
// 	int win_x;
// 	int win_y;
// 	int i;

// 	i = 0;
// 	win_x = 0;
// 	bg_img_path = "bg.xpm";
// 	bg_img = mlx_xpm_file_to_image(mlx_ptr, bg_img_path, &img_width,
// 			&img_height);
// 	while (win_x < win_width)
// 	{
// 		win_y = 0;
// 		while (win_y < win_height)
// 		{
// 			mlx_put_image_to_window(mlx_ptr, new_window, bg_img, win_x, win_y);
// 			win_y += img_height;
// 		}
// 		win_x += img_width;
// 	}
// }