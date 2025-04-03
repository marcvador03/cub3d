/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:27:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/03 15:34:59 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will handle the key press  events
 * 
 * @param k_d mlx_key_data - data about the key event
 * @param param void* - pointer to the data structure
 * @return void
 */
void	key_handler_press(struct mlx_key_data k_d, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (k_d.key == MLX_KEY_ESCAPE)
		exit_normal(d);
	if (k_d.action == MLX_PRESS)
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

/**
 * @brief This function will handle the key release events
 * 
 * @param k_d mlx_key_data - data about the key event
 * @param param void* - pointer to the data structure
 * @return void
 */
void	key_handler_release(struct mlx_key_data k_d, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (k_d.action == MLX_RELEASE)
	{
		if (((k_d.key == MLX_KEY_W || k_d.key == MLX_KEY_UP) && d->pl_mv == FWD)
			|| ((k_d.key == MLX_KEY_S || k_d.key == MLX_KEY_DOWN)
				&& d->pl_mv == BK)
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
 * @param k_d mlx_key_data - data about the key event
 * @param param void* - pointer to the data structure
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
 * @param ptr void* - pointer to the data structure
 * @return void
 */
void	hook_close(void *ptr)
{
	t_data	*d;

	d = (t_data *)ptr;
	exit_normal(d);
}
