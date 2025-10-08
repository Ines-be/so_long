/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   you_won.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:53 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	you_won(t_mlx *game)
{
	int	i;

	game->img_width = (game->width / 2) - 32;
	game->img_height = (game->height / 2) - 32;
	i = 0;
	background(game);
	check_p_pos(game);
	while (i++ < 50000)
	{
		if (i <= 10000)
			you(game);
		if (i > 10000 && i <= 20000)
			won(game);
		if (i > 20000 && i <= 30000)
			you(game);
		if (i > 30000 && i <= 40000)
			won(game);
		if (i > 40000)
			you_won_msg(game);
	}
	return (0);
}

void	check_p_pos(t_mlx *game)
{
	if (game->map->p_pos_y == (game->img_height) / 32)
		game->map->p_pos_y = game->map->rows - 1;
	if (game->map->p_pos_y == (game->img_height + 32) / 32)
		game->map->p_pos_y = game->map->rows - 1;
}

void	you(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_you,
		game->img_width, game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img_grass,
		game->img_width + 32, game->img_height);
	p_left(game);
}

void	won(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_grass,
		game->img_width, game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img_won, game->img_width
		+ 32, game->img_height);
	p_right(game);
}

void	you_won_msg(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_you,
		game->img_width, game->img_height);
	p_left(game);
}
