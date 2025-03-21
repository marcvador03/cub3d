/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:20:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/21 12:58:33 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook_key(mlx_key_d_t k, void *param)
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
}

void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}
