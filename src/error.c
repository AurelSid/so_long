/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:05 by asideris          #+#    #+#             */
/*   Updated: 2024/07/11 18:13:22 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_free(t_map *map, char *error)
{
	int	j;

	j = 0;
	if (map)
	{
		if (map->char_img)
			mlx_destroy_image(map->mlx_ptr, map->char_img);
		if (map->exit_img)
			mlx_destroy_image(map->mlx_ptr, map->exit_img);
		if (map->flowers)
			mlx_destroy_image(map->mlx_ptr, map->flowers);
		if (map->window_ptr)
			mlx_destroy_image(map->mlx_ptr, map->window_ptr);
		ft_free_map(map);
		if (error)
		{
			fprintf(stderr, "Error: %s\n", error);
		}
		if (map->window_ptr)
			mlx_destroy_window(map->mlx_ptr, map->window_ptr);
		if (map->mlx_ptr)
			system("leaks so_long");
		exit(EXIT_FAILURE);
	}
}
