/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:21:51 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/03 15:45:56 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will convert the linked list of map d into a 2D array
 * 
 * @param map_lst
 * @param map_size
 * @return void
 */
void	map_conversion(t_data *d)
{
	int		y;
	t_list	*temp;
	t_pos	*map_size;

	if (!d->map->map_size)
		ftl_err("map_size is not initialized", d);
	map_size = d->map->map_size;
	d->map->arr = (char **)safe_malloc((map_size->y + 1) * sizeof(char *), d);
	y = 0;
	temp = d->map_lst;
	while (temp)
	{
		d->map->arr[y] = ft_strdup((char *)temp->content);
		if (!d->map->arr[y])
			ftl_err("in map conversion", d);
		y++;
		temp = temp->next;
	}
	d->map->arr[y] = NULL;
}

/**
 * @brief This function will find the player's position and direction
 * 
 * @param arr char** - the map array
 * @param pl_pos t_pos* - the player's position
 * @param pl_dir char* - the player's direction
 * 
 * @return void
 */
void	find_player(char **arr, t_pos *pl_pos, char *pl_dir)
{
	int		x;
	int		y;

	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 'N' || arr[y][x] == 'S' || arr[y][x] == 'E'
			|| arr[y][x] == 'W')
			{
				pl_pos->x = x;
				pl_pos->y = y;
				*pl_dir = arr[y][x];
				arr[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief This function will calculate the size of the map
 * 		  by counting the number of lines and the length of the longest line
 * 		  after deleting the lines that are not a map d
 * @param d t_data* - the data structure
 * @return void
 */
void	map_size(t_data *d)
{
	t_list	*temp;

	d->map->map_size->x = 0;
	d->map->map_size->y = 0;
	temp = d->map_lst;
	while (temp)
	{
		d->map->map_size->y++;
		if (d->map->map_size->x < (int)ft_strlen(temp->content))
			d->map->map_size->x = ft_strlen(temp->content);
		temp = temp->next;
	}
}

/**
 * @brief This function will convert the map from char to int
 * 
 * @param d t_data* - the data structure
 * @return void
 */
void	map_arr_to_int(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	d->map->i_map = (int **)safe_malloc(sizeof(int *)
			* (d->map->map_size->y + 1), d);
	while (d->map->arr[y])
	{
		x = 0;
		d->map->i_map[y] = (int *)safe_malloc(sizeof(int)
				* (d->map->map_size->x), d);
		while (d->map->arr[y][x])
		{
			if ((d->map->arr[y][x] == ' ') || (d->map->arr[y][x] == '0'))
				d->map->i_map[y][x] = 0;
			else if (d->map->arr[y][x] == '1')
				d->map->i_map[y][x] = 1;
			else
				ftl_err("in map convertion to int", d);
			x++;
		}
		y++;
	}
	d->map->i_map[y] = NULL;
}
