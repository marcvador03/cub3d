/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:21:51 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/26 18:39:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
