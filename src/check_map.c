/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:10:02 by asideris          #+#    #+#             */
/*   Updated: 2024/07/16 14:07:59 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->collumns)
		{
			if (i == 0 || i == map->rows - 1 || j == 0 || j == map->collumns
				- 1)
			{
				if (map->map[i][j] != '1')
					ft_exit_free(map, "Invalid walls setup");
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_printf_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			write(1, &map->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_check_rows(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->map[0]);
	while (i < map->rows)
	{
		if (ft_strlen(map->map[i]) != len)
		{
			ft_exit_free(map, "Uneven map");
		}
		i++;
	}
	return (1);
}

int	ft_check_valid_tile(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->collumns)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'E')
				ft_exit_free(map, "Unvalid tile in map");
			j++;
		}
		i++;
	}
	return (1);
}
