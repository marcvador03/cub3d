/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:20:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/11 18:28:23 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast_loop(t_mlx *cub, t_raycast *c, t_player *p);

void	hook_key(mlx_key_data_t k, void *param)
{
	t_mlx		*cub;
	double		x;
	double		y;

	cub = (t_mlx *)param;
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		mlx_terminate(cub->mlx);
	else if (k.key == MLX_KEY_UP && k.action == MLX_PRESS)
	{
		cub->player->posX += cub->player->dirX;
		cub->player->posY += cub->player->dirY;
		raycast_loop(cub, cub->raycast, cub->player);
	}
	else if (k.key == MLX_KEY_DOWN && k.action == MLX_PRESS)
	{
		cub->player->posX -= cub->player->dirX;
		cub->player->posY -= cub->player->dirY;
		raycast_loop(cub, cub->raycast, cub->player);
	}
	else if (k.key == MLX_KEY_LEFT && k.action == MLX_PRESS)
	{
		x = cub->player->dirX;
		y = cub->player->dirY;
		cub->player->dirX = x * cos(-0.5) - y * sin(-0.5);
		cub->player->dirY = x * sin(-0.5) + y * cos(-0.5);
		x = cub->player->planeX;
		y = cub->player->planeY;
		cub->player->planeX = x * cos(-0.5) - y * sin(-0.5);
		cub->player->planeY = x * sin(-0.5) + y * cos(-0.5);
		raycast_loop(cub, cub->raycast, cub->player);
	}
	else if (k.key == MLX_KEY_RIGHT && k.action == MLX_PRESS)
	{
		x = cub->player->dirX;
		y = cub->player->dirY;
		cub->player->dirX = x * cos(0.5) - y * sin(0.5);
		cub->player->dirY = x * sin(0.5) + y * cos(0.5);
		x = cub->player->planeX;
		y = cub->player->planeY;
		cub->player->planeX = x * cos(0.5) - y * sin(0.5);
		cub->player->planeY = x * sin(0.5) + y * cos(0.5);
		raycast_loop(cub, cub->raycast, cub->player);
	}
}

void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}
