/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:27 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/11 10:49:23 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast_init(t_mlx *cub);

int	main(int argc, char *argv[])
{
	t_mlx	cub;

	if (argc != 1)
	{
		printf("error in arguments");
		return (1);
	}
	else
		cub.map_path = argv[1];
	cub.win_w = 1080;
	cub.win_h = 1080;
	cub.mlx = mlx_init(cub.win_w, cub.win_h, "CUB3D", true);
	if (cub.mlx == NULL)
		return (1);
	mlx_close_hook(cub.mlx, &hook_close, &cub);
	mlx_key_hook(cub.mlx, &hook_key, &cub);
	raycast_init(&cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	return (0);
}
