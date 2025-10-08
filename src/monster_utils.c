/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:06:02 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_win(t_mlx *game)
{
	mlx_destroy_window(game->mlx, game->win);
	if (game->img_grass)
		mlx_destroy_image(game->mlx, game->img_grass);
	if (game->img_p_front)
		mlx_destroy_image(game->mlx, game->img_p_front);
	if (game->img_p_back)
		mlx_destroy_image(game->mlx, game->img_p_back);
	if (game->img_p_left)
		mlx_destroy_image(game->mlx, game->img_p_left);
	if (game->img_p_right)
		mlx_destroy_image(game->mlx, game->img_p_right);
	if (game->img_item)
		mlx_destroy_image(game->mlx, game->img_item);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	destroy_monster(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clean_exit(game->map);
	return (0);
}

void	destroy_monster(t_mlx *game)
{
	if (game->img_m_front)
		mlx_destroy_image(game->mlx, game->img_m_front);
	if (game->img_m_back)
		mlx_destroy_image(game->mlx, game->img_m_back);
	if (game->img_m_left)
		mlx_destroy_image(game->mlx, game->img_m_left);
	if (game->img_m_right)
		mlx_destroy_image(game->mlx, game->img_m_right);
	if (game->img_you)
		mlx_destroy_image(game->mlx, game->img_you);
	if (game->img_won)
		mlx_destroy_image(game->mlx, game->img_won);
	if (game->img_game)
		mlx_destroy_image(game->mlx, game->img_game);
	if (game->img_over)
		mlx_destroy_image(game->mlx, game->img_over);
}

void	init_monster_pos(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->rows && map->map_og[y][x])
	{
		while (x < map->cols && map->map_og[y][x])
		{
			if (map->map_og[y][x] == 'M')
			{
				map->m_pos_x = x;
				map->m_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	init_bonus(t_mlx *game)
{
	game->img_m_front = 0;
	game->img_m_back = 0;
	game->img_m_left = 0;
	game->img_m_right = 0;
	game->img_you = 0;
	game->img_won = 0;
	game->img_game = 0;
	game->img_over = 0;
}
