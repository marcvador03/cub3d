/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/26 19:19:23 by mfleury          ###   ########.fr       */
/*   Updated: 2025/02/24 11:38:26 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <limits.h>
# include <math.h>

# include "../libft/libft.h"
# include "../mlx42/include/MLX42/MLX42.h"
# include "textures.h"

typedef struct s_mlx
{
	mlx_t	*mlx;
	char	*map_path;
}	t_mlx;

typedef struct s_raycast
{
	double	posX;
	double 	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;

}	t_raycast;

void	free_s(void *ptr);
void	free_d(char **ptr);
void	hook_key(mlx_key_data_t k, void *param);
void	hook_close(void *ptr);

#endif
