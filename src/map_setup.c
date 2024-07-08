/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:03:42 by asideris          #+#    #+#             */
/*   Updated: 2024/07/08 15:50:53 by asideris         ###   ########.fr       */
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
	close(fd);
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

	ft_get_measures(map);
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
		ft_strlcpy(map->map[i], line, map->collumns + 1);
		free(line);
		i++;
	}
	close(fd);
}
