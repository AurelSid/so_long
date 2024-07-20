/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:52 by asideris          #+#    #+#             */
/*   Updated: 2024/07/20 15:02:41 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_token_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->tokens = 0;
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
		ft_exit_free(map, "No tokens");
	return (map->tokens);
}

int	ft_backtrack(t_map *map, int y, int x)
{
	char	original;

	if (x < 0 || x >= map->collumns || y < 0 || y >= map->rows)
		return (0);
	if (map->map[y][x] == '1' || map->map[y][x] == 'V')
		return (0);
	original = map->map[y][x];
	if (map->map[y][x] == 'C')
	{
		map->tokens--;
	}
	else if (map->map[y][x] == 'E')
	{
		map->exit_c--;
	}
	map->map[y][x] = 'V';
	if (map->tokens == 0 && map->exit_c == 0)
	{
		return (1);
	}
	if (ft_backtrack(map, y, x + 1) || ft_backtrack(map, y, x - 1)
		|| ft_backtrack(map, y + 1, x) || ft_backtrack(map, y - 1, x))
		return (1);
	map->map[y][x] = original;
	return (0);
}

int	ft_player_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->player_count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->collumns)
		{
			if (map->map[i][j] == 'C')
				map->player_count++;
			j++;
		}
		i++;
	}
	if (map->player_count != 1)
		ft_exit_free(map, "Bad player count");
	return (map->tokens);
}
