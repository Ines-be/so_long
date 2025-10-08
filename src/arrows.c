/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:41:50 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	arrow_right(t_mlx *game, int p_x, int p_y)
{
	if ((game->map->p_pos_x + 1 == game->map->m_pos_x)
		&& (game->map->p_pos_y == game->map->m_pos_y))
	{
		game_over(game);
		close_win(game);
	}
	if (game->map->map_og[p_y][p_x + 1] != '1')
		move_player_right(game, p_x, p_y);
	else
	{
		background(game);
		walls(game);
		collectibles(game);
		p_right(game);
	}
	move_monster_left(game, game->map->m_pos_x, game->map->m_pos_y);
}

void	arrow_left(t_mlx *game, int p_x, int p_y)
{
	if ((game->map->p_pos_x - 1 == game->map->m_pos_x)
		&& (game->map->p_pos_y == game->map->m_pos_y))
	{
		game_over(game);
		close_win(game);
	}
	if (game->map->map_og[p_y][p_x - 1] != '1')
		move_player_left(game, p_x, p_y);
	else
	{
		background(game);
		walls(game);
		collectibles(game);
		p_left(game);
	}
	move_monster_right(game, game->map->m_pos_x, game->map->m_pos_y);
}

void	arrow_down(t_mlx *game, int p_x, int p_y)
{
	if ((game->map->p_pos_y + 1 == game->map->m_pos_y)
		&& (game->map->p_pos_x == game->map->m_pos_x))
	{
		game_over(game);
		close_win(game);
	}
	if (game->map->map_og[p_y + 1][p_x] != '1')
		move_player_down(game, p_x, p_y);
	else
	{
		background(game);
		walls(game);
		collectibles(game);
		p_front(game);
	}
	move_monster_up(game, game->map->m_pos_x, game->map->m_pos_y);
}

void	arrow_up(t_mlx *game, int p_x, int p_y)
{
	if ((game->map->p_pos_y - 1 == game->map->m_pos_y)
		&& (game->map->p_pos_x == game->map->m_pos_x))
	{
		game_over(game);
		close_win(game);
	}
	if (game->map->map_og[p_y - 1][p_x] != '1')
		move_player_up(game, p_x, p_y);
	else
	{
		background(game);
		walls(game);
		collectibles(game);
		p_back(game);
	}
	move_monster_down(game, game->map->m_pos_x, game->map->m_pos_y);
}
