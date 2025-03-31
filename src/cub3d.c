/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:27 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/31 17:50:27 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_args(int argc, char **argv, t_data *d)
{
	if (argc != 2)
		ftl_err("in arguments", d);
	else
	{
		//d->mlx = (mlx_t *)safe_malloc(sizeof(mlx_t), d);
		d->map_path = ft_strdup(argv[1]);
		if (!d->map_path)
			ftl_err("in malloc", d);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)safe_malloc(sizeof(t_data), NULL);
	structs_init(d);
	check_args(argc, argv, d);
	parsing_process(d);
	d->win_w = 1080;
	d->win_h = 1080;
	d->mlx = mlx_init(d->win_w, d->win_h, "CUB3D", true);
	if (!d->mlx)
		ftl_err("mlx_init() failed", d);
	
	mlx_key_hook(d->mlx, key_handler, d);
	mlx_loop_hook(d->mlx, &move_player, d);
	mlx_close_hook(d->mlx, &hook_close, &d);
	raycast_init(d);
	mlx_loop(d->mlx);
	//mlx_terminate(d->mlx);
	exit_normal(d);
}
