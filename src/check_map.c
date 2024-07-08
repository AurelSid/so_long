/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:10:02 by asideris          #+#    #+#             */
/*   Updated: 2024/07/08 15:57:25 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_walls(t_map *map)
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
			if (i == 0 || i == map->rows - 1 || j == 0 || j == map->collumns
				- 1)
			{
				if (map->map[i][j] != '1')
				{
					printf("err : wrong wall setup");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
int	ft_check_rows(t_map *map)
{
	int i;
	int len;

	i = 1;

	len = ft_strlen(map->map[0]);

	while (i < map->rows)
	{
		if (ft_strlen(map->map[i]) != len)
		{
			return (0);
			printf("Wrong map row allignments");
		}
		i++;
	}
	return (1);
}