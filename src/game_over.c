/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:25:08 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_over(t_mlx *game)
{
	int	i;

	game->img_width = (game->width / 2) - 32;
	game->img_height = (game->height / 2) - 32;
	i = 0;
	background(game);
	check_m_pos(game);
	while (i++ < 50000)
	{
		if (i <= 10000)
			game_msg(game);
		if (i > 10000 && i <= 20000)
			over(game);
		if (i > 20000 && i <= 30000)
			game_msg(game);
		if (i > 30000 && i <= 40000)
			over(game);
		if (i > 40000)
			game_over_msg(game);
	}
	return (0);
}

void	check_m_pos(t_mlx *game)
{
	if (game->map->m_pos_y == (game->img_height) / 32)
		game->map->m_pos_y = game->map->rows - 1;
	if (game->map->m_pos_y == (game->img_height + 32) / 32)
		game->map->m_pos_y = game->map->rows - 1;
}

void	game_msg(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_game,
		game->img_width, game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img_grass,
		game->img_width + 32, game->img_height);
	m_left(game);
}

void	over(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_grass,
		game->img_width, game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img_over,
		game->img_width + 32, game->img_height);
	m_right(game);
}

void	game_over_msg(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_game,
		game->img_width, game->img_height);
	m_left(game);
}
