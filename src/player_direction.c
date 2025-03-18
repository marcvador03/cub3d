/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:43:13 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/18 13:57:47 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_north_south(t_player *player, t_map *map)
{
	if (map->player_dir == 'N')
	{
		player->dirX = 0;
		player->dirY = -1;
		player->planeX = 0.66;
		player->planeY = 0;
	}
	else if (map->player_dir == 'S')
	{
		player->dirX = 0;
		player->dirY = 1;
		player->planeX = -0.66;
		player->planeY = 0;
	}
}

static void set_player_east_west(t_player *player, t_map *map)
{
	if (map->player_dir == 'E')
	{
		player->dirX = 1;
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = 0.66;
	}
	else if (map->player_dir == 'W')
	{
		player->dirX = -1;
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = -0.66;
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
	set_player_north_south(d->cub->player, d->map);
	set_player_east_west(d->cub->player, d->map);
	d->cub->player->posX = d->map->pl_pos->x;
	d->cub->player->posY = d->map->pl_pos->y;
}
// function to be added to 'raycast.c' -> int raycast_init(t_mlx *cub)
