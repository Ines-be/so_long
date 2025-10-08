/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:25:00 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player_right(t_mlx *game, int x, int y)
{
	if (game->map->count->moves != INT_MAX)
		game->map->count->moves += 1;
	ft_printf("Number of movements: %d\n", game->map->count->moves);
	game->map->p_pos_x += 1;
	if (game->map->map_og[y][x + 1] == 'C')
	{
		game->map->map_og[y][x + 1] = 0;
		game->map->count->collectible -= 1;
	}
	background(game);
	walls(game);
	collectibles(game);
	p_right(game);
}

void	move_player_down(t_mlx *game, int x, int y)
{
	if (game->map->count->moves != INT_MAX)
		game->map->count->moves += 1;
	ft_printf("Number of movements: %d\n", game->map->count->moves);
	game->map->p_pos_y += 1;
	if (game->map->map_og[y + 1][x] == 'C')
	{
		game->map->map_og[y + 1][x] = 0;
		game->map->count->collectible -= 1;
	}
	background(game);
	walls(game);
	collectibles(game);
	p_front(game);
}

void	move_player_left(t_mlx *game, int x, int y)
{
	if (game->map->count->moves != INT_MAX)
		game->map->count->moves += 1;
	ft_printf("Number of movements: %d\n", game->map->count->moves);
	game->map->p_pos_x -= 1;
	if (game->map->map_og[y][x - 1] == 'C')
	{
		game->map->map_og[y][x - 1] = 0;
		game->map->count->collectible -= 1;
	}
	background(game);
	walls(game);
	collectibles(game);
	p_left(game);
}

void	move_player_up(t_mlx *game, int x, int y)
{
	if (game->map->count->moves != INT_MAX)
		game->map->count->moves += 1;
	ft_printf("Number of movements: %d\n", game->map->count->moves);
	game->map->p_pos_y -= 1;
	if (game->map->map_og[y - 1][x] == 'C')
	{
		game->map->map_og[y - 1][x] = 0;
		game->map->count->collectible -= 1;
	}
	background(game);
	walls(game);
	collectibles(game);
	p_back(game);
}
