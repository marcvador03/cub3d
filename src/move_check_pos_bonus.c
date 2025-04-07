/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check_pos_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:59:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/07 16:41:29 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

/**
 * @brief Check if the new position is valid on the map 
 * 		  (bonus:) and if it is not inside a wall.
 * 
 * @param d t_data* - pointer to the data structure
 * @param x double - x position
 * @param y double - y position
 * @return bool - true if the position is valid, false otherwise
 */
static bool	is_valid_pos_on_map(t_data *d, double x, double y)
{
	if ((x < 0.25 || x >= (double)(d->map->map_size->x) - 1.25)
		|| (y < 0.25 || y >= (double)(d->map->map_size->y) - 0.25)
		|| x < 0.0f || x >= (double)(d->map->map_size->x)
		|| y < 0.0f || y >= (double)(d->map->map_size->y))
		return (false);
	if (d->map->arr[(int)y][(int)x] == '1')
		return (false);
	return (true);
}

/**
 * @brief Check if the new position is valid on the map
 * 
 * @param d t_data* - pointer to the data structure
 * @param p t_player* - pointer to the player structure
 * @param new_x double - new x position
 * @param new_y double - new y position
 * @return bool - true if the position is valid, false otherwise
 */
bool	is_move_valid(t_data *d, t_player *p, double new_x, double new_y)
{
	bool	is_valid;

	is_valid = false;
	if (is_valid_pos_on_map(d, new_x, p->pos_y))
	{
		p->pos_x = new_x;
		is_valid = true;
	}
	if (is_valid_pos_on_map(d, p->pos_x, new_y))
	{
		p->pos_y = new_y;
		is_valid = true;
	}
	return (is_valid);
}
