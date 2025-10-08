/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:02:14 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	key_hook(int keycode, t_mlx *game)
// {
// 	(void)game;
// 	printf("key_hook = %d\n", keycode);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_game	map;
	t_mlx	game;

	if (ac != 2)
		open_error();
	name_check(av[1]);
	init_map(&map, av[1]);
	check_map(&map);
	init_mlx(&game, &map);
	mlx_hook(game.win, 17, 0, close_win, &game);
	display_start(&game);
	// mlx_key_hook(game.win, update_pos, &game);
	mlx_hook(game.win, 2, (1L << 0), update_pos, &game);
	mlx_loop(game.mlx);
}
