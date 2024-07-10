/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:05 by asideris          #+#    #+#             */
/*   Updated: 2024/07/10 16:35:46 by asideris         ###   ########.fr       */
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

	if (error)
	{
		fprintf(stderr, "Error: %s\n", error);
	}

	exit(EXIT_FAILURE);
}