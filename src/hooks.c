/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:20:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/07 18:51:38 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_mlx *cub, t_render *r);

void	hook_key(mlx_key_data_t k, void *param)
{
	t_mlx		*cub;

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
}

void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}
