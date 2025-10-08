/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:50:11 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *map)
{
	check_len(map);
	check_first_and_last(map);
	check_middles(map);
	check_chars(map);
	init_p_pos(map);
	check_path(map);
	if ((map->rows * 32 > 1080) || (map->cols * 32 > 1920))
		map_error("Map is too big.", map);
	if ((map->rows <= 3) || (map->cols <= 3))
		map_error("Map is too small, player can't win.", map);
}

// meme len pour toutes les lignes et au moins 3 lignes
void	check_len(t_game *map)
{
	int	y;
	int	base_len;
	int	line_len;

	y = 0;
	if (map->rows < 3)
		map_error("Less than 3 lines.", map);
	base_len = ft_strlen_c(map->mapcopy[y], '\n');
	while (y < map->rows)
	{
		line_len = ft_strlen(map->mapcopy[y]);
		if (ft_find(map->mapcopy[y], '\n'))
			line_len--;
		if (line_len != base_len)
			map_error("Different size lines.", map);
		y++;
	}
}

// check que tous les chars sont valides et compte les E, C, P
void	check_chars(t_game *map)
{
	int		y;
	int		x;
	int		base_len;

	y = 0;
	x = 0;
	base_len = ft_strlen_c(map->mapcopy[0], '\n');
	while (y < map->rows)
	{
		while (x < base_len)
		{
			if (valid_char(map->mapcopy[y][x], map->count) < 0)
				map_error("Invalid char.", map);
			x++;
		}
		y++;
		x = 0;
	}
	check_count(map, map->count);
}

void	check_first_and_last(t_game *map)
{
	int	x;
	int	last_row;

	x = 0;
	last_row = map->rows - 1;
	while (map->mapcopy[0][x] != '\n')
	{
		if (map->mapcopy[0][x] != '1')
			map_error("Not surrounded by walls.", map);
		x++;
	}
	x = 0;
	while (map->mapcopy[last_row][x])
	{
		if (map->mapcopy[last_row][x] != '1')
			map_error("Not surrounded by walls.", map);
		x++;
	}
}

// verifier qu'il y a bien un 1 au debut et a la fin de chaque ligne
void	check_middles(t_game *map)
{
	int	y;
	int	last_col;

	y = 1;
	last_col = ft_strlen_c(map->mapcopy[0], '\n') - 1;
	while (y != (map->rows - 1))
	{
		if (map->mapcopy[y][0] != '1' || map->mapcopy[y][last_col] != '1')
			map_error("Not surrounded by walls.", map);
		y++;
	}
}
