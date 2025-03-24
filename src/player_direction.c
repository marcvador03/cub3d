/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:43:13 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/24 14:41:06 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_north_south(t_player *player, t_map *map)
{
	if (map->player_dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (map->player_dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

static void	set_player_east_west(t_player *player, t_map *map)
{
	if (map->player_dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (map->player_dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

/**
 * @brief Function to set the player direction
 * The value 0.66 is derived from the tangent of half the field of view angle.
 * In many 2D raycasting engines, the FOV is set to 66 degrees, which is 
 * approximately 1.15 radians. The tangent of half of this angle 
 * (0.575 radians) is approximately 0.66.
 * 
 * @param player_dir the player direction
 * @return void
 */
void	set_player_location_and_dir(t_data *d)
{
	set_player_north_south(d->player, d->map);
	set_player_east_west(d->player, d->map);
	d->player->pos_x = d->map->pl_pos->x;
	d->player->pos_y = d->map->pl_pos->y;
}
// function to be added to 'raycast.c' -> int raycast_init(t_mlx *cub)
