/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:51:18 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/26 18:40:14 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_arr_temp(t_map *map)
{
	int		y;
	char	**arr_temp;

	arr_temp = (char **)safe_malloc((map->map_size->y + 1) * sizeof(char *));
	y = 0;
	while (y < map->map_size->y)
	{
		arr_temp[y] = ft_strdup(map->arr[y]);
		if (!arr_temp[y])
			return (NULL);
		arr_temp[y][map->map_size->x] = '\0';
		y++;
	}
	arr_temp[y] = NULL;
	return (arr_temp);
}

static void	ft_fill(char **tab, t_pos *size, t_pos *cur, char to_fill)
{
	t_pos	temp;

	if (cur->y < 0 || cur->y >= size->y || cur->x < 0 || cur->x >= size->x
		|| tab[cur->y][cur->x] == 'F' || tab[cur->y][cur->x] == '1'
		|| tab[cur->y][cur->x] == 'E')
		return ;
	tab[cur->y][cur->x] = 'F';
	temp = (t_pos){cur->x - 1, cur->y};
	ft_fill(tab, size, &temp, to_fill);
	temp = (t_pos){cur->x + 1, cur->y};
	ft_fill(tab, size, &temp, to_fill);
	temp = (t_pos){cur->x, cur->y - 1};
	ft_fill(tab, size, &temp, to_fill);
	temp = (t_pos){cur->x, cur->y + 1};
	ft_fill(tab, size, &temp, to_fill);
}

void	ft_flood_fill(char **tab, t_pos *size, t_pos *begin)
{
	ft_fill(tab, size, begin, tab[begin->y][begin->x]);
}

