/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbennou <inbennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:44:07 by inbennou          #+#    #+#             */
/*   Updated: 2025/10/08 14:52:08 by inbennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**fill_map(t_game *map, char *av)
{
	int		fd;
	char	*line;
	char	**filled_map;
	int		y;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		open_error();
	filled_map = ft_calloc((map->rows + 1), sizeof(char *));
	if (!filled_map)
		exit(EXIT_FAILURE);
	line = get_next_line(fd, 0);
	y = 0;
	while (ft_find(line, '\n') == 1)
	{
		filled_map[y] = dup_line(line);
		y++;
		free(line);
		line = get_next_line(fd, 0);
	}
	filled_map[y] = dup_line(line);
	free_and_close(fd, line);
	return (filled_map);
}

char	*dup_line(char *line)
{
	char	*filled_map;

	if (line && line[0] != '\0')
		filled_map = ft_strdup(line);
	else
		filled_map = 0;
	return (filled_map);
}

int	count_rows(int fd)
{
	int		rows;
	char	*line;

	rows = 0;
	line = get_next_line(fd, 0);
	if (!line || line[0] == '\0')
		return (0);
	while (ft_find(line, '\n'))
	{
		rows++;
		free(line);
		line = get_next_line(fd, 0);
		if (!line || line[0] == '\0')
		{
			free_line(fd, line);
			return (rows);
		}
	}
	rows++;
	free_line(fd, line);
	return (rows);
}

int	valid_char(char c, t_chars *count)
{
	if (c == 'P')
		count->player += 1;
	else if (c == 'E')
		count->exit += 1;
	else if (c == 'C')
		count->collectible += 1;
	else if (c == 'M')
		count->monster += 1;
	else if (c == '1' || c == '0' || c == 'M')
		return (1);
	else
		return (-1);
	return (1);
}

void	wall_fill(t_game *map, int row, int col)
{
	if (row < 0 || col < 0 || row >= map->rows || col >= map->cols)
		return ;
	if (map->mapcopy[row][col] == '1')
		return ;
	map->mapcopy[row][col] = '1';
	wall_fill(map, row - 1, col);
	wall_fill(map, row + 1, col);
	wall_fill(map, row, col - 1);
	wall_fill(map, row, col + 1);
}
