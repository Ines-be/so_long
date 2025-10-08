/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:22:17 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:39:21 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_error(char *error, t_game *map)
{
	if (map->map_og)
		free_tab(map->map_og);
	if (map->mapcopy)
		free_tab(map->mapcopy);
	if (map->count)
		free(map->count);
	ft_printf("Error\nInvalid map. %s\n", error);
	exit(EXIT_FAILURE);
}

void	open_error(void)
{
	ft_printf("Error\nCan't open map.\n");
	exit(EXIT_FAILURE);
}

void	clean_exit(t_game *map)
{
	if (map->map_og)
		free_tab(map->map_og);
	if (map->mapcopy)
		free_tab(map->mapcopy);
	if (map->count)
		free(map->count);
	exit(1);
}
