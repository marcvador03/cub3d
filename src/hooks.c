/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:51:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/18 13:49:08 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//#include "MLX42/MLX42.h"

/**
 * @brief Function to handle key presses
 * 
 * @param k_d struct with key data
 * @param param pointer to the data struct
 * @return void
 */
void	key_handler(struct mlx_key_d k_d, void *param)
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

/**
 * @brief Function to close the mlx window
 * 
 * @param param pointer to the mlx struct
 * @return void
 */
void	hook_close(void *ptr)
{
	t_mlx	*cub;

	cub = (t_mlx *)ptr;
	mlx_terminate(cub->mlx);
}
