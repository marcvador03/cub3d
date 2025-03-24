/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:27 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/24 12:27:34 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)safe_malloc(sizeof(t_data), NULL);
	if (argc != 2)
		ftl_err("in arguments", d);
	else
	{
		d->cub = (t_mlx *)safe_malloc(sizeof(t_mlx), d);
		d->map_path = ft_strdup(argv[1]);
		if (!d->map_path)
			ftl_err("in malloc", d);
	}
	d->cub->win_w = 1080;
	d->cub->win_h = 1080;
	parsing_process(d);
	d->cub->mlx = mlx_init(d->cub->win_w, d->cub->win_h, "CUB3D", true);
	if (!d->cub->mlx)
		ftl_err("mlx_init() failed", d);
	mlx_close_hook(d->cub->mlx, &hook_close, &d->cub);
	mlx_key_hook(d->cub->mlx, key_handler, &d->cub);
	mlx_loop_hook(d->cub->mlx, &move_player, d);
	raycast_init(d);
	mlx_loop(d->cub->mlx);
	mlx_terminate(d->cub->mlx);
	free_data(d);
	exit(0);
}
