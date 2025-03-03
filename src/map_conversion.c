/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:21:51 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/03 23:56:42 by milosz           ###   ########.fr       */
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
		if (map_size->x < (int)ft_strlen(temp->line))
			map_size->x = ft_strlen(temp->line);
		temp = temp->next;
	}
	return (map_size);
}

/**
 * @brief This function will convert the linked list of map data into a 2D array
 * 
 * @param map_list
 * @param map_size
 * @return char** - map converted to 2D array
 */
char	**map_conversion(t_list *map_list, t_pos *map_size)
{
	int		y;
	char	**map;
	t_list	*temp;

	map = (char **)safe_malloc((map_size->y + 1) * sizeof(char *));
	y = 0;
	temp = map_list;
	while (temp)
	{
		map[y] = ft_strdup(temp->line);
		if (!map[y])
			return (NULL);
		map[y][ft_strlen(temp->line)] = '\0';
		y++;
		temp = temp->next;
	}
	map[y] = NULL;
	return (map);
}

void	find_player(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (map->arr[x])
	{
		y = 0;
		while (map->arr[x][y])
		{
			if (map->arr[x][y] == 'N' || map->arr[x][y] == 'S' || map->arr[x][y] == 'E' || map->arr[x][y] == 'W')
			{
				map->player_pos->x = x;
				map->player_pos->y = y;
				map->player_dir = map->arr[x][y];
				map->arr[x][y] = '0';
				return ;
			}
			y++;
		}
		x++;
	}
}
