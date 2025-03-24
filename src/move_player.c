/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:36:17 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/24 13:20:12 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	move_player_fwd_bkw(int direction, t_player *p, t_data *d)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (direction == FWD)
	{
		new_x = p->pos_x + p->dir_x / MV_SPD_FCTR;
		new_y = p->pos_y + p->dir_y / MV_SPD_FCTR;
	}
	else if (direction == BK)
	{
		new_x = p->pos_x - p->dir_x / MV_SPD_FCTR;
		new_y = p->pos_y - p->dir_y / MV_SPD_FCTR;
	}
	return (is_move_valid(d, p, new_x, new_y));
}

static bool	move_player_left_right(int direction, t_player *p, t_data *d)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	if (direction == LEFT)
	{
		new_x = p->pos_x + p->dir_x / MV_SPD_FCTR;
		new_y = p->pos_y - p->dir_y / MV_SPD_FCTR;
	}
	else if (direction == RIGHT)
	{
		new_x = p->pos_x - p->dir_x / MV_SPD_FCTR;
		new_y = p->pos_y + p->dir_y / MV_SPD_FCTR;
	}
	return (is_move_valid(d, p, new_x, new_y));
}

static bool	rotate_player(int direction, t_player *p)
{
	double	rt_angle;

	rt_angle = (double)(direction) / RT_ANGLE_FCTR;
	p->dir_x = p->dir_x * cos(rt_angle) - p->dir_y * sin(rt_angle);
	p->dir_y = p->dir_x * sin(rt_angle) + p->dir_y * cos(rt_angle);
	p->plane_x = p->plane_x * cos(rt_angle) - p->plane_y * sin(rt_angle);
	p->plane_y = p->plane_x * sin(rt_angle) + p->plane_y * cos(rt_angle);
	return (true);
}

void	move_player(void *param)
{
	bool	has_moved;
	t_data	*d;

	d = (t_data *)param;
	has_moved = false;
	if (d->pl_mv != 0 && (d->pl_mv == FWD || d->pl_mv == BK))
		has_moved = move_player_fwd_bkw(d->pl_mv, d->cub->player, d);
	if (d->pl_mv != 0 && (d->pl_mv == LEFT || d->pl_mv == RIGHT))
		has_moved = move_player_left_right(d->pl_mv, d->cub->player, d);
	if (d->pl_rotate != 0)
		has_moved = rotate_player(d->pl_rotate, d->cub->player);
	if (has_moved)
		raycast_loop(d, d->cub->raycast, d->cub->player);
}
