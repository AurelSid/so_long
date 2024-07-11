/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:19:37 by asideris          #+#    #+#             */
/*   Updated: 2024/07/11 16:14:18 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_setup_struct(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return ;
	map->bg_img = mlx_xpm_file_to_image(map->mlx_ptr, "bg.xpm", &map->tile_w,
			&map->tile_h);
	map->char_img = mlx_xpm_file_to_image(map->mlx_ptr, "static_char.xpm",
			&map->tile_w, &map->tile_h);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, "wall.xpm", &map->tile_w,
			&map->tile_h);
	map->flowers = mlx_xpm_file_to_image(map->mlx_ptr, "blue_flowers.xpm",
			&map->tile_w, &map->tile_h);
	map->exit_img = mlx_xpm_file_to_image(map->mlx_ptr, "exit.xpm",
			&map->tile_w, &map->tile_h);
	map->score = 0;
	map->exit_c = 1;
}

void	ft_set_player_pos(t_map *map)
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
			if (map->map[i][j] == 'P')
			{
				map->player_pos_x = j;
				map->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
	if (map->player_pos_y == 0)
		printf("No player_found");
}

void	ft_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%c", map->map[i][17]);
	j++;
}

int	ft_check_err(t_map *map)
{
	if (!ft_token_count(map))
		return (0);
	if (map->player_pos_y == 0)
		return (0);
	if (!ft_check_walls(map))
		return (0);
	if (!ft_check_rows(map))
		return (0);
	if (!ft_check_valid_tile(map))
		return (0);
	if (!ft_backtrack(map, map->player_pos_y, map->player_pos_x))
		ft_exit_free(map, "Unsolvable map");
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	map = (t_map *)malloc(sizeof(t_map));
	ft_setup_struct(map);
	ft_read_map(map, argv[1]);
	ft_set_player_pos(map);
	ft_check_err(map);
	ft_setup_struct(map);
	ft_read_map(map, argv[1]);
	map->window_ptr = mlx_new_window(map->mlx_ptr, (map->collumns
				* map->tile_w), (map->rows * map->tile_h), "so_long");
	if (!map->mlx_ptr)
		return (0);
	ft_populate_map(map);
	mlx_key_hook(map->window_ptr, ft_move, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
