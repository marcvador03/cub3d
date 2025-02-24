/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/24 11:38:26 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../mlx42/include/MLX42/MLX42.h"

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

}	t_raycast;


void	hook_key(mlx_key_data_t k, void *param);
void	hook_close(void *ptr);

#endif
