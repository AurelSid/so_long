/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:05 by asideris          #+#    #+#             */
/*   Updated: 2024/07/23 18:30:07 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_images(t_map *map)
{
	if (map->char_img)
	{
		mlx_destroy_image(map->mlx_ptr, map->char_img);
	}
	if (map->exit_img)
	{
		mlx_destroy_image(map->mlx_ptr, map->exit_img);
	}
	if (map->flowers)
	{
		mlx_destroy_image(map->mlx_ptr, map->flowers);
	}
}

void	free_map_and_error(t_map *map, char *error)
{
	if (map->map != NULL)
	{
		ft_free_map(map);
		free(map->map);
		map->map = NULL;
	}
	if (error)
	{
		write(2, "Error: ", 7);
		write(2, error, ft_strlen(error));
	}
}

void	destroy_window_and_exit(t_map *map)
{
	if (map->window_ptr != NULL)
	{
		mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	}
	if (map->mlx_ptr != NULL)
	{
		free(map->mlx_ptr);
	}
	exit(EXIT_FAILURE);
}

void	ft_exit_free(t_map *map, char *error)
{
	if (map)
	{
		destroy_images(map);
		free_map_and_error(map, error);
		destroy_window_and_exit(map);
	}
}

void	ft_check_extention(char *path)
{
	char	**str;

	str = ft_split(path, '.');
	if (!str[1] || ft_strncmp("ber", str[1], ft_strlen(str[1]) + 3))
	{
		ft_free_split(str);
		write(2, "Bad file extention , program will now quit...", 45);
		exit(0);
	}
	ft_free_split(str);
}
