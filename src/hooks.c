/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:20:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/07 23:41:46 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_mlx *cub, t_render *r);

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
		cub->render->posX += cub->render->dirX;
		cub->render->posY += cub->render->dirY;
		render_loop(cub, cub->render);
	}
	else if (k.key == MLX_KEY_DOWN && k.action == MLX_PRESS)
	{
		cub->render->posX -= cub->render->dirX;
		cub->render->posY -= cub->render->dirY;
		render_loop(cub, cub->render);
	}
	else if (k.key == MLX_KEY_LEFT && k.action == MLX_PRESS)
	{
		x = cub->render->dirX;
		y = cub->render->dirY;
		cub->render->dirX = x * cos(-0.5) - y * sin(-0.5);
		cub->render->dirY = x * sin(-0.5) + y * cos(-0.5);
		x = cub->render->planeX;
		y = cub->render->planeY;
		cub->render->planeX = x * cos(-0.5) - y * sin(-0.5);
		cub->render->planeY = x * sin(-0.5) + y * cos(-0.5);
		render_loop(cub, cub->render);
	}
	else if (k.key == MLX_KEY_RIGHT && k.action == MLX_PRESS)
	{
		x = cub->render->dirX;
		y = cub->render->dirY;
		cub->render->dirX = x * cos(0.5) - y * sin(0.5);
		cub->render->dirY = x * sin(0.5) + y * cos(0.5);
		x = cub->render->planeX;
		y = cub->render->planeY;
		cub->render->planeX = x * cos(0.5) - y * sin(0.5);
		cub->render->planeY = x * sin(0.5) + y * cos(0.5);
		render_loop(cub, cub->render);
	}
}

void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}
