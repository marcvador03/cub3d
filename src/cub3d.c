/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:27 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/19 17:20:09 by mfleury          ###   ########.fr       */
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
	free_data(d);
	exit(0);
	/*cub.mlx = mlx_init(1920, 1080, "CUB3D", true);
	if (cub.mlx == NULL)
		return (1);
	mlx_close_hook(cub.mlx, &hook_close, &cub);
	mlx_key_hook(cub.mlx, &hook_key, &cub);
	raycast_init(&cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	return (0);*/
}
