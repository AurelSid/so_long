/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:59:51 by asideris          #+#    #+#             */
/*   Updated: 2024/07/07 17:32:52 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_format(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->collumns)
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
					map->wall, j * map->tile_w, i * map->tile_h);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
					map->flowers, j * map->tile_w, i * map->tile_h);
			else if (map->map[i][j] == 'C')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
					map->char_img, j * map->tile_w, i * map->tile_h);
			}
			j++;
		}
		i++;
	}
}
void	ft_fill_bg(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->collumns)
		{
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->bg_img,
				j * map->tile_w, i * map->tile_h);
			j++;
		}
		i++;
	}
}
void	ft_populate_map(t_map *map)
{
	int	win_x;
	int	win_y;

	win_x = 0;
	win_y = 0;
	ft_fill_bg(map);
	ft_format(map);
}
