/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:03:42 by asideris          #+#    #+#             */
/*   Updated: 2024/07/06 14:03:54 by asideris         ###   ########.fr       */
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
	ft_populate_map(map);
	close(fd);
}

void ft_populate_map(t_map *map)
{
	int win_x;
	int win_y;
	int i;
	
	i = 0;
	win_x = 0;
	win_y = 0;
	map->bg_img_path = "bg.xpm";
	while (win_x < map->collumns)
	{
		win_y = 0;
		while (win_y < map->rows)
		{
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->bg_img, win_x, win_y);
			win_y += map->bg_img_height;
		}
		win_x += map->bg_img_width;
	}
}