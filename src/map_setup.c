/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:03:42 by asideris          #+#    #+#             */
/*   Updated: 2024/07/11 18:36:37 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_map_exists(t_map *map)
{
	if (!open(map->map_path, O_RDONLY) || open(map->map_path, O_RDONLY) == -1)
	{
		if (map)
		{
			if (map->char_img)
				mlx_destroy_image(map->mlx_ptr, map->char_img);
			if (map->exit_img)
				mlx_destroy_image(map->mlx_ptr, map->exit_img);
			if (map->flowers)
				mlx_destroy_image(map->mlx_ptr, map->flowers);
			// if (map->window_ptr)
			// 	mlx_clear_window(map->mlx_ptr, map->window_ptr);
			if (map->mlx_ptr)
			{
				printf("avant");
				// mlx_destroy_window(map->mlx_ptr, map->window_ptr);
				free(map->mlx_ptr);
				printf("apres");
			}
			exit(1);
		}
	}
	return (1);
}

void	ft_get_measures(t_map *map)
{
	int		fd;
	char	*str;
	int		len;

	len = 0;
	map->collumns = 0;
	map->rows = 1;
	ft_check_map_exists(map);
	fd = open(map->map_path, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		free(str);
	len = ft_strlen(str) - 1;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			break ;
		}
		map->collumns = ft_strlen(str) - 1;
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

void	ft_read_map(t_map *map, char *file_name)
{
	int		fd;
	int		i;
	char	*line;
	int		j;

	ft_get_measures(map);
	ft_allocate_map(map);
	fd = open(file_name, O_RDONLY);
	j = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		line = get_next_line(fd);
		while (line[j] != '\n' && line[j] != '\0')
		{
			map->map[i][j] = line[j];
			j++;
		}
		map->map[i][j] = '\0';
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
}

void	ft_free_map(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->rows)
	{
		free(map->map[j]);
		j++;
	}
	free(map->map);
}
