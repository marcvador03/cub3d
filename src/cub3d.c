/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:27 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/26 18:38:35 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_mlx	cub;

	if (argc != 1)
	{
		printf("Error\n in arguments");
		return (1);
	}
	else
		cub.map_path = argv[1];
	cub.mlx = mlx_init(1920, 1080, "CUB3D", true);
	if (cub.mlx == NULL)
		return (1);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	return (0);
}
