/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:40:29 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/06 17:54:45 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will calculate the size of the map
 * 		  by counting the number of lines and the length of the longest line
 * 		  after deleting the lines that are not a map data
 * @param map_list
 * @return t_pos*
 */
t_pos	*map_size(t_list *map_list)
{
	t_pos	*map_size;
	t_list	*temp;

	map_size = (t_pos *)safe_malloc(sizeof(t_pos));
	map_size->x = 0;
	map_size->y = 0;
	temp = map_list;
	while (temp)
	{
		map_size->y++;
		if (map_size->x < (int)ft_strlen(temp->content))
			map_size->x = ft_strlen(temp->content);
		temp = temp->next;
	}
	return (map_size);
}

void	is_map_symbols_correct(char **map, t_pos *map_size)
{
	int		x;
	int		y;
	int		player_count;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != ' ' && map[x][y] != '1' && map[x][y] != '0'
					&& map[x][y] != 'N' && map[x][y] != 'S'
						&& map[x][y] != 'E' && map[x][y] != 'W')
				ftl_err("in map symbols");
			else if (map[x][y] == 'N' || map[x][y] == 'S'
					|| map[x][y] == 'E' || map[x][y] == 'W')
				player_count++;
			y++;
		}
		x++;
	}
	if (player_count != 1)
		ftl_err("in player count");
}
