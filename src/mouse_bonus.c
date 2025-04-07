/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:29:36 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/07 17:36:12 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

static bool	rotate_player(int direction, t_player *p)
{
	double	rt_angle;

	rt_angle = (double)(direction) / 40;
	p->dir_x = p->dir_x * cos(rt_angle) - p->dir_y * sin(rt_angle);
	p->dir_y = p->dir_x * sin(rt_angle) + p->dir_y * cos(rt_angle);
	p->plane_x = p->plane_x * cos(rt_angle) - p->plane_y * sin(rt_angle);
	p->plane_y = p->plane_x * sin(rt_angle) + p->plane_y * cos(rt_angle);
	return (true);
}

void	mouse_move(double xpos, double ypos, void *param)
{
	t_mouse	*m;
	
	m = (t_mouse *)param;
	ypos += 0;
	if ((int32_t)xpos < m->x - 1)
	{
		printf("mouse moved right\n");
		rotate_player(-TURN_R, m->d->player);
	}
	else if ((int32_t)xpos > m->x + 1)
	{
		printf("mouse moved left\n");
		rotate_player(-TURN_L, m->d->player);
	}
	else if ((int32_t)xpos > m->x - 1 && (int32_t)xpos < m->x + 1)
	{
		printf("mouse moved within the marigin \n");
	}
	raycast_loop(m->d, m->d->raycast, m->d->player);
	mlx_get_mouse_pos(m->d->mlx, &m->x, &m->y);
	/*else if (m->y < (int32_t)ypos)
	{
		printf("mouse moved down\n");
	}
	else if (m->y > (int32_t)ypos)
	{
		printf("mouse moved up\n");
	}*/
}
