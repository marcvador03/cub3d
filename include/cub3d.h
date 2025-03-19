/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/19 16:56:49 by mfleury          ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1

typedef struct	s_render
{
	double	wallX;
	int		pixelX;
	int		pixelY;
	double	step;
	double	pixel_pos;

}	t_render;

typedef struct s_player
{
	double	posX;
	double 	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;

}	t_player;

typedef struct s_raycast
{
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	int		mapX;
	int		mapY;
	int		hit_flag;
	int		side_flag;
	double	walldist;
	int		lineHeight;
	int		wall_start;
	int		wall_end;

}	t_raycast;

typedef struct s_mlx
{
	mlx_t			*mlx;
	t_raycast		*raycast;
	t_player		*player;
	t_render		*render;
	char			*map_path;
	int				**map;
	int				win_w;
	int				win_h;
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}	t_mlx;


void	free_s(void *ptr);
void	free_d(char **ptr);
void	hook_key(mlx_key_data_t k, void *param);
void	hook_close(void *ptr);

#endif
