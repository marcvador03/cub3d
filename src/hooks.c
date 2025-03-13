/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:51:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/13 18:47:08 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_data *d)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_terminate(d->cub->mlx);
	if (key == MLX_KEY_W || key == MLX_KEY_UP)
		d->pl_move = UP;
	if (key == MLX_KEY_S || key == MLX_KEY_DOWN)
		d->pl_move = DOWN;
	if (key == MLX_KEY_A)
		d->pl_move = LEFT;
	if (key == MLX_KEY_D)
		d->pl_move = RIGHT;
	if (key == MLX_KEY_LEFT)
		d->pl_rotate = TURN_L;
	if (key == MLX_KEY_RIGHT)
		d->pl_rotate = TURN_R;
	return (0);
}

static int	key_release_handler(int key, t_data *d)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_terminate(d->cub->mlx);
	if (((key == MLX_KEY_W || key == MLX_KEY_UP) && d->pl_move == UP)
		|| ((key == MLX_KEY_S || key == MLX_KEY_DOWN) && d->pl_move == DOWN)
			|| (key == MLX_KEY_A && d->pl_move == LEFT)
				|| (key == MLX_KEY_D && d->pl_move == RIGHT))
		d->pl_move = RESET;
	if ((key == MLX_KEY_LEFT && d->pl_rotate == TURN_L)
		|| (key == MLX_KEY_RIGHT && d->pl_rotate == TURN_R))
		d->pl_rotate = RESET;
	return (0);
}

void	hook_key(mlx_key_data_t k, t_data *d, void *param)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, exit_normal, d);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, d)
}

void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}