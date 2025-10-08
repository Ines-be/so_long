/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_monster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:18:29 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	m_front(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_m_front,
		game->map->m_pos_x * 32, game->map->m_pos_y * 32);
	return (0);
}

int	m_back(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_m_back,
		game->map->m_pos_x * 32, game->map->m_pos_y * 32);
	return (0);
}

int	m_left(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_m_left,
		game->map->m_pos_x * 32, game->map->m_pos_y * 32);
	return (0);
}

int	m_right(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_m_right,
		game->map->m_pos_x * 32, game->map->m_pos_y * 32);
	return (0);
}
