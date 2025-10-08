/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:01:10 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_imgs(t_mlx *game)
{
	int	w;
	int	h;

	game->img_grass = mlx_xpm_file_to_image(game->mlx, "img/grass.xpm", &w, &h);
	if (!game->img_grass)
		close_win(game);
	init_p_imgs(game);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "img/item.xpm", &w, &h);
	if (!game->img_item)
		close_win(game);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &w, &h);
	if (!game->img_exit)
		close_win(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &w, &h);
	if (!game->img_wall)
		close_win(game);
	init_m_imgs(game);
}

void	init_p_imgs(t_mlx *game)
{
	int	w;
	int	h;

	game->img_p_front = mlx_xpm_file_to_image(game->mlx, "img/p_front.xpm", &w,
			&h);
	if (!game->img_p_front)
		close_win(game);
	game->img_p_back = mlx_xpm_file_to_image(game->mlx, "img/p_back.xpm", &w,
			&h);
	if (!game->img_p_back)
		close_win(game);
	game->img_p_left = mlx_xpm_file_to_image(game->mlx, "img/p_left.xpm", &w,
			&h);
	if (!game->img_p_left)
		close_win(game);
	game->img_p_right = mlx_xpm_file_to_image(game->mlx, "img/p_right.xpm", &w,
			&h);
	if (!game->img_p_right)
		close_win(game);
}

void	init_m_imgs(t_mlx *game)
{
	int	w;
	int	h;

	game->img_m_front = mlx_xpm_file_to_image(game->mlx, "img/m_front.xpm", &w,
			&h);
	if (!game->img_m_front)
		close_win(game);
	game->img_m_back = mlx_xpm_file_to_image(game->mlx, "img/m_back.xpm", &w,
			&h);
	if (!game->img_m_back)
		close_win(game);
	game->img_m_left = mlx_xpm_file_to_image(game->mlx, "img/m_left.xpm", &w,
			&h);
	if (!game->img_m_left)
		close_win(game);
	game->img_m_right = mlx_xpm_file_to_image(game->mlx, "img/m_right.xpm", &w,
			&h);
	if (!game->img_m_right)
		close_win(game);
}

void	init_msg(t_mlx *game)
{
	int	w;
	int	h;

	game->img_you = mlx_xpm_file_to_image(game->mlx, "img/you.xpm", &w, &h);
	if (!game->img_you)
		close_win(game);
	game->img_won = mlx_xpm_file_to_image(game->mlx, "img/won!.xpm", &w, &h);
	if (!game->img_won)
		close_win(game);
	game->img_game = mlx_xpm_file_to_image(game->mlx, "img/game.xpm", &w, &h);
	if (!game->img_game)
		close_win(game);
	game->img_over = mlx_xpm_file_to_image(game->mlx, "img/over.xpm", &w, &h);
	if (!game->img_over)
		close_win(game);
}

void	init_base(t_mlx *game)
{
	game->img_grass = 0;
	game->img_p_front = 0;
	game->img_p_back = 0;
	game->img_p_left = 0;
	game->img_p_right = 0;
	game->img_item = 0;
	game->img_exit = 0;
	game->img_wall = 0;
}
