/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:27:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/02 14:52:54 by milosz           ###   ########.fr       */
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

void	key_handler_press(struct mlx_key_data k_d, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (k_d.key == MLX_KEY_ESCAPE)
		exit_normal(d);
	if (k_d.action == MLX_PRESS) // Check if the key is pressed
	{
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
	}
}

void	key_handler_release(struct mlx_key_data k_d, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (k_d.action == MLX_RELEASE) // Check if the key is released
	{
		if (((k_d.key == MLX_KEY_W || k_d.key == MLX_KEY_UP) && d->pl_mv == FWD)
			|| ((k_d.key == MLX_KEY_S || k_d.key == MLX_KEY_DOWN) && d->pl_mv == BK)
			|| (k_d.key == MLX_KEY_A && d->pl_mv == LEFT)
			|| (k_d.key == MLX_KEY_D && d->pl_mv == RIGHT))
			d->pl_mv = RESET;
		if ((k_d.key == MLX_KEY_LEFT && d->pl_rotate == TURN_L)
			|| (k_d.key == MLX_KEY_RIGHT && d->pl_rotate == TURN_R))
			d->pl_rotate = RESET;
	}
}

/**
 * @brief This function will handle the key press and release events
 * 
 * @param k_d
 * @param param
 * @return void
 */
void	key_handler(struct mlx_key_data k_d, void *param)
{
	key_handler_press(k_d, param);
	key_handler_release(k_d, param);
}

/**
 * @brief This function will close the window and exit the program
 * 
 * @param ptr
 * @return void
 */
void	hook_close(void *ptr)
{
	t_data	*d;

	d = (t_data *)ptr;
	exit_normal(d);
}

