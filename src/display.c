/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:28:16 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	background(t_mlx *game)
{
	int	img_width;
	int	img_height;

	img_width = 0;
	img_height = 0;
	while (img_height < game->height)
	{
		while (img_width < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_grass,
				img_width, img_height);
			img_width += 32;
		}
		img_height += 32;
		img_width = 0;
	}
	return (0);
}

int	walls(t_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map->rows)
	{
		while (x < game->map->cols)
		{
			if (game->map->map_og[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* 32, y * 32);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	collectibles(t_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map->rows)
	{
		while (x < game->map->cols)
		{
			if (game->map->map_og[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_item, x
					* 32, y * 32);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

int	display_start(t_mlx *game)
{
	background(game);
	p_front(game);
	m_front(game);
	walls(game);
	collectibles(game);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xFFFFFF, "Moves:");
	mlx_string_put(game->mlx, game->win, 75, 32, 0xFFFFFF, "0");
	return (0);
}

int	display_exit(t_mlx *game)
{
	int	x;
	int	y;

	x = game->map->exit_pos_x * 32;
	y = game->map->exit_pos_y * 32;
	mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x, y);
	return (0);
}
