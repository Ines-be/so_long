/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:24:43 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_count(t_chars *count)
{
	count->player = 0;
	count->exit = 0;
	count->collectible = 0;
	count->monster = 0;
	count->moves = 0;
}

void	init_map(t_game *map, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		open_error();
	map->rows = count_rows(fd);
	close(fd);
	map->map_og = NULL;
	map->mapcopy = NULL;
	map->cols = 0;
	map->p_pos_x = 0;
	map->p_pos_y = 0;
	map->exit_pos_x = 0;
	map->exit_pos_y = 0;
	map->m_pos_x = 0;
	map->m_pos_y = 0;
	map->map_og = fill_map(map, av);
	map->mapcopy = fill_map(map, av);
	map->count = malloc(sizeof (t_chars));
	if (!map->count)
		clean_exit(map);
	init_count(map->count);
}

void	init_p_pos(t_game *map)
{
	int	x;
	int	y;

	map->rows = tab_len(map->map_og);
	map->cols = ft_strlen_c(map->map_og[0], '\n');
	x = 0;
	y = 0;
	while (y < map->rows && map->map_og[y][x])
	{
		while (x < map->cols && map->map_og[y][x])
		{
			if (map->map_og[y][x] == 'P')
			{
				map->p_pos_x = x;
				map->p_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	init_exit_pos(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->rows && map->map_og[y][x])
	{
		while (x < map->cols && map->map_og[y][x])
		{
			if (map->map_og[y][x] == 'E')
			{
				map->exit_pos_x = x;
				map->exit_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	init_mlx(t_mlx *game, t_game *map)
{
	game->map = map;
	game->width = map->cols * 32;
	game->height = map->rows * 32;
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(map);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		clean_exit(map);
	}
	init_base(game);
	init_bonus(game);
	init_imgs(game);
	init_msg(game);
	init_exit_pos(map);
	init_monster_pos(map);
}
