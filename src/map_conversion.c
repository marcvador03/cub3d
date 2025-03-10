/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:21:51 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/10 18:31:45 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/**
 * @brief This function will convert the linked list of map data into a 2D array
 * 
 * @param map_list
 * @param map_size
 * @return char** - map converted to 2D array
 */
void	map_conversion(t_data *data)
{
	int		y;
	char	**map;
	t_list	*temp;
	t_pos *map_size;

	map_size = data->map->map_size;
	map = (char **)safe_malloc((map_size->y + 1) * sizeof(char *), data);
	y = 0;
	temp = data->map_list;
	while (temp)
	{
		map[y] = ft_strdup((char *)temp->content);
		if (!map[y])
			ftl_err("in map conversion", data);
		map[y][ft_strlen(temp->content)] = '\0';
		y++;
		temp = temp->next;
	}
	map[y] = NULL;
	y = 0;
	data->map->arr = map;
}

void	find_player(char **arr , t_pos *player_pos, char *player_dir)
{
	int		x;
	int		y;

	x = 0;
	while (arr[x])
	{
		y = 0;
		while (arr[x][y])
		{
			if (arr[x][y] == 'N' || arr[x][y] == 'S' || arr[x][y] == 'E' || arr[x][y] == 'W')
			{
				player_pos->x = x;
				player_pos->y = y;
				*player_dir = arr[x][y];
				arr[x][y] = '0';
				return ;
			}
			y++;
		}
		x++;
	}
}

/**
 * @brief This function will calculate the size of the map
 * 		  by counting the number of lines and the length of the longest line
 * 		  after deleting the lines that are not a map data
 * @param map_list
 * @return t_pos*
 */
void	map_size(t_data *data)
{
	t_pos	*map_size;
	t_list	*temp;

	map_size = (t_pos *)safe_malloc(sizeof(t_pos), data);
	map_size->x = 0;
	map_size->y = 0;
	temp = data->map_list;
	while (temp)
	{
		map_size->y++;
		if (map_size->x < (int)ft_strlen(temp->content))
			map_size->x = ft_strlen(temp->content);
		temp = temp->next;
	}
	data->map->map_size = map_size;
}
