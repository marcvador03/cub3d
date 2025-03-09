/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:40:29 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/09 18:07:18 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/**
 * @brief Check if map symbols are correct
 * 
 * @param map char**
 * @return void
 */
void	is_map_symbols_correct(char **map)
{
	int		x;
	int		y;
	int		player_count = 0;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != ' ' && map[y][x] != '1' && map[y][x] != '0'
					&& map[y][x] != 'N' && map[y][x] != 'S'
						&& map[y][x] != 'E' && map[y][x] != 'W')
				ftl_err("in map symbols");
			else if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
		ftl_err("in player count");
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
static void is_map_closed_checks(char **map, t_pos *map_size, int x, int y)
{
	if (x == 0 || x == map_size->x - 1 || y == 0 ||	y == map_size->y - 1) 
		ftl_err("map isn't closed by walls on the borders of the map");
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
			|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '
				|| !map[y - 1][x] || !map[y + 1][x]
						|| !map[y][x - 1] || !map[y][x + 1])
		ftl_err("map isn't closed by walls - lacks walls");
	if (map[y - 1][x - 1] == ' ' || map[y + 1][x + 1] == ' '
			|| map[y - 1][x + 1] == ' ' || map[y + 1][x - 1] == ' '
				|| !map[y - 1][x - 1] || !map[y + 1][x + 1]
					|| !map[y - 1][x + 1] || !map[y + 1][x - 1])
		ftl_err("map isn't closed by walls - lacks corners");
}

/**
 * @brief Checks if map is closed by walls
 * 
 * @param map char**
 * @param map_size t_pos*
 * @return void
 */
void	is_map_closed(char **map, t_pos *map_size)
{
	int		x;
	int		y;

	if (!map || !map[0] || !map[0][0] || !map_size)
		ftl_err("map is empty");
	if (map_size->x < 2 || map_size->y < 2)
		ftl_err("map is empty or too small");
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				is_map_closed_checks(map, map_size, x, y);
			x++;
		}
		y++;
	}
}
