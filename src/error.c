/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:05 by asideris          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:05 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_free(t_map *map, char *error)
{
	int j = 0;

	while (j < map->rows)
	{
		free(map->map[j]);
		j++;
	}
	free(map->map);
	mlx_destroy_image(map->mlx_ptr, map->char_img);
	mlx_destroy_image(map->mlx_ptr, map->exit_img);
	mlx_destroy_image(map->mlx_ptr, map->flowers);
	mlx_destroy_image(map->mlx_ptr, map->window_ptr);

	if (error)
	{
		fprintf(stderr, "Error: %s\n", error);
	}
	mlx_destroy_window(map->mlx_ptr, map->window_ptr);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}