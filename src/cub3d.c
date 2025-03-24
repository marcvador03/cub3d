/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:27 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/24 12:08:56 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	cub;
	t_data	*d;

	if (argc != 2)
		ftl_err("in arguments", NULL);
	else
		cub.map_path = argv[1];
	d = (t_data *)safe_malloc(sizeof(t_data), NULL);
	parsing_process(&cub, d);
	//exit(0);
	cub.d = d;
	cub.win_w = 1080;
	cub.win_h = 1080;
	cub.mlx = mlx_init(cub.win_w, cub.win_h, "CUB3D", false);
	if (cub.mlx == NULL)
		return (1);
	mlx_close_hook(cub.mlx, &hook_close, &cub);
	mlx_key_hook(cub.mlx, &hook_key, &cub);
	raycast_init(&cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	free_data(d);
	return (0);
}
