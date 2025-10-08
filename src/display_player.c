/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:24:39 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	p_front(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_p_front,
		game->map->p_pos_x * 32, game->map->p_pos_y * 32);
	return (0);
}

int	p_back(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_p_back,
		game->map->p_pos_x * 32, game->map->p_pos_y * 32);
	return (0);
}

int	p_left(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_p_left,
		game->map->p_pos_x * 32, game->map->p_pos_y * 32);
	return (0);
}

int	p_right(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_p_right,
		game->map->p_pos_x * 32, game->map->p_pos_y * 32);
	return (0);
}
