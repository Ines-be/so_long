/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:10:26 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_count(t_game *map, t_chars *count)
{
	if (count->exit < 1)
		map_error("You need one exit (E).", map);
	if (count->exit > 1)
		map_error("You can't have more than one exit (E).", map);
	if (count->player < 1)
		map_error("You need one starting position (P).", map);
	if (count->player > 1)
		map_error("You can't have more than one starting position (P).", map);
	if (count->collectible == 0)
		map_error("You need at least one collectible (C).", map);
	if (count->monster != 1)
		map_error("You need one monster (M).", map);
}

void	check_path(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	wall_fill(map, map->p_pos_y, map->p_pos_x);
	while (map->mapcopy[y])
	{
		while (map->mapcopy[y][x] && x < map->cols)
		{
			if (map->mapcopy[y][x] == 'C')
				map_error("Player can't reach all the collectibles.", map);
			if (map->mapcopy[y][x] == 'E')
				map_error("Player can't reach the exit.", map);
			x++;
		}
		y++;
		x = 0;
	}
}

void	name_check(char *str)
{
	int	i;
	int	j;

	if (!str || !str[0])
		open_error();
	i = ft_strlen(str) - 1;
	j = skip_path(str);
	if (ft_strlen(str + j) == 4)
		open_error();
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
			- 3] != '.')
		open_error();
}

int	skip_path(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (ft_strchr(str, '/') != 0)
	{
		len = ft_strlen(str) - 1;
		while (str[len] != '/')
			len--;
		len += 1;
	}
	return (len);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
