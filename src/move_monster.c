/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:23:36 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_monster_right(t_mlx *game, int m_x, int m_y)
{
	if (game->map->map_og[m_y][m_x + 1] != '1')
		game->map->m_pos_x += 1;
	m_right(game);
}

void	move_monster_down(t_mlx *game, int m_x, int m_y)
{
	if (game->map->map_og[m_y + 1][m_x] != '1')
		game->map->m_pos_y += 1;
	m_front(game);
}

void	move_monster_left(t_mlx *game, int m_x, int m_y)
{
	if (game->map->map_og[m_y][m_x - 1] != '1')
		game->map->m_pos_x -= 1;
	m_left(game);
}

void	move_monster_up(t_mlx *game, int m_x, int m_y)
{
	if (game->map->map_og[m_y - 1][m_x] != '1')
		game->map->m_pos_y -= 1;
	m_back(game);
}
