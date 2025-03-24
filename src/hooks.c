/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:27:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/24 13:02:29 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	hook_key(mlx_key_data_t k, void *param)
{
	t_mlx		*cub;
	double		x;
	double		y;

	cub = (t_mlx *)param;
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		mlx_terminate(cub->mlx);
	else if (k.key == MLX_KEY_UP && k.action == MLX_PRESS)
	{
		cub->player->pos_x += cub->player->dir_x;
		cub->player->pos_y += cub->player->dir_y;
		raycast_loop(cub, cub->raycast, cub->player);
	}
	else if (k.key == MLX_KEY_DOWN && k.action == MLX_PRESS)
	{
		cub->player->pos_x -= cub->player->dir_x;
		cub->player->pos_y -= cub->player->dir_y;
		raycast_loop(cub, cub->raycast, cub->player);
	}
	else if (k.key == MLX_KEY_LEFT && k.action == MLX_PRESS)
	{
		x = cub->player->dir_x;
		y = cub->player->dir_y;
		cub->player->dir_x = x * cos(-0.5) - y * sin(-0.5);
		cub->player->dir_y = x * sin(-0.5) + y * cos(-0.5);
		x = cub->player->plane_x;
		y = cub->player->plane_y;
		cub->player->plane_x = x * cos(-0.5) - y * sin(-0.5);
		cub->player->plane_y = x * sin(-0.5) + y * cos(-0.5);
		raycast_loop(cub, cub->raycast, cub->player);
	}
	else if (k.key == MLX_KEY_RIGHT && k.action == MLX_PRESS)
	{
		x = cub->player->dir_x;
		y = cub->player->dir_y;
		cub->player->dir_x = x * cos(0.5) - y * sin(0.5);
		cub->player->dir_y = x * sin(0.5) + y * cos(0.5);
		x = cub->player->plane_x;
		y = cub->player->plane_y;
		cub->player->plane_x = x * cos(0.5) - y * sin(0.5);
		cub->player->plane_y = x * sin(0.5) + y * cos(0.5);
		raycast_loop(cub, cub->raycast, cub->player);
	}
}*/

void	key_handler(struct mlx_key_data k_d, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (k_d.key == MLX_KEY_ESCAPE)
		mlx_terminate(d->cub->mlx);
	if (k_d.key == MLX_KEY_W || k_d.key == MLX_KEY_UP)
		d->pl_mv = FWD;
	if (k_d.key == MLX_KEY_S || k_d.key == MLX_KEY_DOWN)
		d->pl_mv = BK;
	if (k_d.key == MLX_KEY_A)
		d->pl_mv = LEFT;
	if (k_d.key == MLX_KEY_D)
		d->pl_mv = RIGHT;
	if (k_d.key == MLX_KEY_LEFT)
		d->pl_rotate = TURN_L;
	if (k_d.key == MLX_KEY_RIGHT)
		d->pl_rotate = TURN_R;
	if (((k_d.key == MLX_KEY_W || k_d.key == MLX_KEY_UP) && d->pl_mv == FWD)
		|| ((k_d.key == MLX_KEY_S || k_d.key == MLX_KEY_DOWN) && d->pl_mv == BK)
		|| (k_d.key == MLX_KEY_A && d->pl_mv == LEFT)
		|| (k_d.key == MLX_KEY_D && d->pl_mv == RIGHT))
		d->pl_mv = RESET;
	if ((k_d.key == MLX_KEY_LEFT && d->pl_rotate == TURN_L)
		|| (k_d.key == MLX_KEY_RIGHT && d->pl_rotate == TURN_R))
		d->pl_rotate = RESET;
}

void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}
