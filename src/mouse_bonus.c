/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:29:36 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/08 15:43:46 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

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
