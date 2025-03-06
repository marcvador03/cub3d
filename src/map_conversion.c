/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:21:51 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/06 17:47:24 by mpietrza         ###   ########.fr       */
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
		map[y] = ft_strdup((char *)temp->content);
		if (!map[y])
			return (NULL);
		map[y][ft_strlen(temp->content)] = '\0';
		y++;
		temp = temp->next;
	}
	map[y] = NULL;
	y = 0;
	return (map);
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
				player_dir = arr[x][y];
				arr[x][y] = '0';
				return ;
			}
			y++;
		}
		x++;
	}
}
