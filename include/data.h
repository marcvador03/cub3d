/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:50:03 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/18 13:44:15 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "cub3d.h"

typedef struct	s_render
{
	double	wallX;
	int		pixelX;
	int		pixelY;
	double	step;
	double	pixel_pos;
	int		color;

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
	char			**map;
	int				win_w;
	int				win_h;
	mlx_image_t		*image;
	mlx_texture_t	*texture;
	mlx_texture_t	*main_tex;
}	t_mlx;

typedef struct s_gr_data
{
	char			*no_tx;
	char			*so_tx;
	char			*we_tx;
	char			*ea_tx;
	unsigned int	f_clr[3];
	unsigned int	c_clr[3];
}	t_gr_data;

/* struct for storing position on a map*/
typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

/* struct for creating and managing the map */
typedef struct s_map
{
	char		**arr;
	t_pos		*map_size;
	t_pos		*pl_pos;
	char		player_dir;
	int			x;
	int			y;
}		t_map;

/* !!! struct for storing all the data !!! */
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_gr_data	*txs;
	t_map		*map;
	t_list		*ln_lst;
	t_list		*map_lst;
	t_mlx		*cub;
	int			pl_mv;
	int			pl_rotate;
}	t_data;

#endif
