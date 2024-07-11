/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:52 by asideris          #+#    #+#             */
/*   Updated: 2024/07/11 16:12:56 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_token_count(t_map *map)
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
			if (map->map[i][j] == 'C')
				map->tokens++;
			j++;
		}
		i++;
	}
	if (map->tokens == 0)
	{
		printf("Add tokens");
	}
	return (map->tokens);
}

int	ft_backtrack(t_map *map, int y, int x)
{
	if (x < 0 || x >= map->collumns || y < 0 || y >= map->rows)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return (0);
	if (map->map[y][x] == 'C')
	{
		map->tokens--;
		map->map[y][x] = 'V';
	}
	if (map->map[y][x] == 'E')
	{
		map->exit_c--;
		map->map[y][x] = 'V';
	}
	if (map->tokens == 0 && map->exit_c == 0)
	{
		printf("backtracking map ok");
		return (1);
	}
	map->map[y][x] = 'V';
	if (ft_backtrack(map, y, x + 1) || ft_backtrack(map, y, x - 1)
		|| ft_backtrack(map, y + 1, x) || ft_backtrack(map, y - 1, x))
		return (1);
	map->map[y][x] = ' ';
	return (0);
}
