/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:40:29 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/12 12:13:00 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check if map symbols are correct
 * 
 * @param d t_data*
 * @return void
 */
void	is_map_symbols_correct(t_data *d)
{
	int		x;
	int		y;
	int		player_count;

	y = 0;
	player_count = 0;
	while (d->map->arr[y])
	{
		x = 0;
		while (d->map->arr[y][x])
		{
			if (d->map->arr[y][x] != ' ' && d->map->arr[y][x] != '1'
				&& d->map->arr[y][x] != '0' && d->map->arr[y][x] != 'N'
				&& d->map->arr[y][x] != 'S' && d->map->arr[y][x] != 'E'
				&& d->map->arr[y][x] != 'W')
				ftl_err("in map symbols", d);
			else if (d->map->arr[y][x] == 'N' || d->map->arr[y][x] == 'S'
				|| d->map->arr[y][x] == 'E' || d->map->arr[y][x] == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
		ftl_err("in player count", d);
}

/**
 * @brief 3 checks if map is closed by walls
 * 
 * @param map char**
 * @param map_size t_pos*
 * @param x int
 * @param y int
 * @return void
 */
static bool	is_map_closed_checks(char **map, t_pos *map_size, int x, int y)
{
	if (x == 0 || x == map_size->x - 1 || y == 0 || y == map_size->y - 1)
		return (false);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
			|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '
				|| !map[y - 1][x] || !map[y + 1][x]
						|| !map[y][x - 1] || !map[y][x + 1])
		return (false);
	if (map[y - 1][x - 1] == ' ' || map[y + 1][x + 1] == ' '
			|| map[y - 1][x + 1] == ' ' || map[y + 1][x - 1] == ' '
				|| !map[y - 1][x - 1] || !map[y + 1][x + 1]
					|| !map[y - 1][x + 1] || !map[y + 1][x - 1])
		return (false);
	return (true);
}

/**
 * @brief Checks if map is closed by walls
 * 
 * @param map char**
 * @param map_size t_pos*
 * @return void
 */
void	is_map_closed(t_data *d)
{
	int		x;
	int		y;
	char	**map;

	map = d->map->arr;
	if (!map || !map[0] || !map[0][0] || !d->map->map_size)
		ftl_err("map is empty", d);
	if (d->map->map_size->x < 2 || d->map->map_size->y < 2)
		ftl_err("map is empty or too small", d);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W')
				if (is_map_closed_checks(map, d->map->map_size, x, y)
					== false)
					ftl_err("map is not closed", d);
			x++;
		}
		y++;
	}
}
