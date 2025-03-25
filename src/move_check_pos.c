/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:59:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/25 15:41:56 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_pos_on_map(t_data *d, double x, double y)
{
	if ((x < 0.25 || x >= (double)(d->map->map_size->x) - 1.25)
		|| (y < 0.25 || y >= (double)(d->map->map_size->y) - 0.25)
		|| (int)x < 0 || (int)x >= d->map->map_size->x
		|| (int)y < 0 || (int)y >= d->map->map_size->y)
		return (false);
	return (true);
}

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
