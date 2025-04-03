/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:45 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/03 15:56:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# include "cub3d_bonus.h"

typedef struct s_render
{
	double	wall_x;
	int		pixel_x;
	int		pixel_y;
	double	step;
	double	pixel_pos;

}	t_render;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;

}	t_player;

typedef struct s_raycast
{
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	int		map_x;
	int		map_y;
	int		hit_flag;
	int		side_flag;
	double	walldist;
	int		lineheight;
	int		wall_start;
	int		wall_end;

}	t_raycast;

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
	int			**i_map;
	t_pos		*map_size;
	t_pos		*pl_pos;
	char		player_dir;
	int			x;
	int			y;
}		t_map;

/* !!! struct for storing all the data !!! */
typedef struct s_data
{
	t_gr_data		*txs;
	mlx_t			*mlx;
	t_raycast		*raycast;
	t_player		*player;
	t_render		*render;
	int				win_w;
	int				win_h;
	mlx_image_t		*image;
	mlx_texture_t	*texture_no;
	mlx_texture_t	*texture_so;
	mlx_texture_t	*texture_we;
	mlx_texture_t	*texture_ea;
	t_map			*map;
	t_list			*ln_lst;
	t_list			*map_lst;
	int				pl_mv;
	int				pl_rotate;
	char			*map_path;
}	t_data;

#endif
