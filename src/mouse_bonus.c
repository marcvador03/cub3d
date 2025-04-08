/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:29:36 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/08 15:23:52 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

time_t	get_time_ms(void);
time_t	get_time_us(void);
static bool	rotate_player(int direction, t_player *p)
{
	double	rt_angle;

	rt_angle = (double)(-direction) / RT_ANGLE_FCTR;
	p->dir_x = p->dir_x * cos(rt_angle) - p->dir_y * sin(rt_angle);
	p->dir_y = p->dir_x * sin(rt_angle) + p->dir_y * cos(rt_angle);
	p->plane_x = p->plane_x * cos(rt_angle) - p->plane_y * sin(rt_angle);
	p->plane_y = p->plane_x * sin(rt_angle) + p->plane_y * cos(rt_angle);
	return (true);
}
static void	mouse_loop(t_mouse *m, int32_t final, int32_t start, int dir)
{
	int	i;

	i = 0;
	while (i != (final - start) && i <= MOUSE_THROTTLE)
	{
		rotate_player(dir, m->d->player);
		i++;
	}
	raycast_loop(m->d, m->d->raycast, m->d->player);
	mlx_get_mouse_pos(m->d->mlx, &m->x, &m->y);
	m->cnt += i;
	return ;
}

void	mouse_move(double xpos, double ypos, void *param)
{
	t_mouse	*m;
	
	m = (t_mouse *)param;
	ypos += 0;
	if (m->cnt != 0 && m->cnt < MOUSE_THROTTLE)
	{
		m->cnt++;
		return ;
	}
	else if (m->cnt != 0 && m->cnt >= MOUSE_THROTTLE)
		m->cnt = 0;
	printf("Mouse move: %d %lf\n", m->x, xpos);
	if ((int32_t)xpos < m->x - MOUSE_STEP)
	{
		mouse_loop(m, m->x, (int32_t)xpos, TURN_L);
		return ;
	}
	else if ((int32_t)xpos > m->x + MOUSE_STEP)
	{
		mouse_loop(m, (int32_t)xpos, m->x, TURN_R);
		return ;
	}
	else if ((int32_t)xpos > m->x - MOUSE_STEP && (int32_t)xpos < m->x + MOUSE_STEP)
		m->cnt++;
}
