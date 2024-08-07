/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:55:24 by asideris          #+#    #+#             */
/*   Updated: 2024/07/16 14:53:32 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_up(t_map *map)
{
	char	*moves;

	if (map->map[map->player_pos_y - 1][map->player_pos_x] != '1')
	{
		if (map->map[map->player_pos_y][map->player_pos_x] == 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
				map->exit_img, map->player_pos_x * map->tile_w,
				map->player_pos_y * map->tile_h);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->bg_img,
				map->player_pos_x * map->tile_w, map->player_pos_y
				* map->tile_h);
		map->player_pos_y -= 1;
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->char_img,
			map->player_pos_x * map->tile_w, map->player_pos_y * map->tile_h);
		map->moves++;
		moves = ft_itoa(map->moves);
		write(1, moves, ft_strlen(moves));
		write(1, "\n", 1);
	}
}

void	ft_move_down(t_map *map)
{
	char	*moves;

	if (map->map[map->player_pos_y + 1][map->player_pos_x] != '1')
	{
		if (map->map[map->player_pos_y][map->player_pos_x] == 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
				map->exit_img, map->player_pos_x * map->tile_w,
				map->player_pos_y * map->tile_h);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->bg_img,
				map->player_pos_x * map->tile_w, map->player_pos_y
				* map->tile_h);
		map->player_pos_y += 1;
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->char_img,
			map->player_pos_x * map->tile_w, map->player_pos_y * map->tile_h);
		map->moves++;
		moves = ft_itoa(map->moves);
		write(1, moves, ft_strlen(moves));
		write(1, "\n", 1);
	}
}

void	ft_move_left(t_map *map)
{
	char	*moves;

	if (map->map[map->player_pos_y][map->player_pos_x - 1] != '1')
	{
		if (map->map[map->player_pos_y][map->player_pos_x] == 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
				map->exit_img, map->player_pos_x * map->tile_w,
				map->player_pos_y * map->tile_h);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->bg_img,
				map->player_pos_x * map->tile_w, map->player_pos_y
				* map->tile_h);
		map->player_pos_x -= 1;
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->char_img,
			map->player_pos_x * map->tile_w, map->player_pos_y * map->tile_h);
		map->moves++;
		moves = ft_itoa(map->moves);
		write(1, moves, ft_strlen(moves));
		write(1, "\n", 1);
	}
}

void	ft_move_right(t_map *map)
{
	char	*moves;

	if (map->map[map->player_pos_y][map->player_pos_x + 1] != '1')
	{
		if (map->map[map->player_pos_y][map->player_pos_x] == 'E')
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr,
				map->exit_img, map->player_pos_x * map->tile_w,
				map->player_pos_y * map->tile_h);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->bg_img,
				map->player_pos_x * map->tile_w, map->player_pos_y
				* map->tile_h);
		map->player_pos_x += 1;
		mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->char_img,
			map->player_pos_x * map->tile_w, map->player_pos_y * map->tile_h);
		map->moves++;
		moves = ft_itoa(map->moves);
		write(1, moves, ft_strlen(moves));
		write(1, "\n", 1);
	}
}

int	ft_move(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == 123)
		ft_move_left(map);
	else if (keycode == 124)
		ft_move_right(map);
	else if (keycode == 125)
		ft_move_down(map);
	else if (keycode == 126)
		ft_move_up(map);
	else if (keycode == 53)
		exit(0);
	if (map->map[map->player_pos_y][map->player_pos_x] == 'C')
	{
		map->tokens--;
		map->map[map->player_pos_y][map->player_pos_x] = '0';
	}
	if (map->map[map->player_pos_y][map->player_pos_x] == 'E')
	{
		if (map->tokens == 0)
			exit(0);
	}
	return (0);
}
