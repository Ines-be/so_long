/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:57 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	update_pos(int keycode, t_mlx *game)
{
	int	p_y;
	int	p_x;
	int	m_y;
	int	m_x;

	p_y = game->map->p_pos_y;
	p_x = game->map->p_pos_x;
	m_y = game->map->m_pos_y;
	m_x = game->map->m_pos_x;
	if (keycode == 65307)
		close_win(game);
	if (keycode == KEY_ARROW_RIGHT)
		arrow_right(game, p_x, p_y);
	if (keycode == KEY_ARROW_DOWN)
		arrow_down(game, p_x, p_y);
	if (keycode == KEY_ARROW_LEFT)
		arrow_left(game, p_x, p_y);
	if (keycode == KEY_ARROW_UP)
		arrow_up(game, p_x, p_y);
	display_moves(game);
	end_game(game);
	return (0);
}

void	display_moves(t_mlx *game)
{
	char	*moves;

	moves = ft_itoa(game->map->count->moves);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 75, 32, 0xFFFFFF, moves);
	free(moves);
}

void	end_game(t_mlx *game)
{
	if (game->map->count->collectible == 0)
	{
		display_exit(game);
		if ((game->map->p_pos_x == game->map->exit_pos_x)
			&& (game->map->p_pos_y == game->map->exit_pos_y))
		{
			you_won(game);
			close_win(game);
		}
	}
	if ((game->map->p_pos_x == game->map->m_pos_x)
		&& (game->map->p_pos_y == game->map->m_pos_y))
	{
		game_over(game);
		close_win(game);
	}
}
