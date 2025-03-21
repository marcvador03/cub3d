/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/21 14:04:32 by mfleury          ###   ########.fr       */
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
# include "../libft/getnextline/get_next_line.h"
# include "../mlx42/include/MLX42/MLX42.h"
# include "textures.h"
# include "macros.h"
# include "data.h"

# define FALSE 0
# define TRUE 1

/* !!! struct for storing all the data !!! */
typedef struct	s_render
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
	double 	pos_y;
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

typedef struct s_gr_d
{
	char			*no_tx;
	char			*so_tx;
	char			*we_tx;
	char			*ea_tx;
	unsigned int	f_clr[3];
	unsigned int	c_clr[3];
}	t_gr_d;

/* struct for storing position on a map*/
typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

/* struct for creating and managing the map */
typedef struct s_map
{
	char	**arr;
	t_pos	*map_size;
	t_pos	*pl_pos;
	char	player_dir;
	int		x;
	int		y;
}		t_map;

typedef struct s_data
{
	t_gr_d		*txs;
	t_map		*map;
	t_list		*ln_lst;
	t_list		*map_lst;
	//t_mlx		*cub;
}	t_data;

typedef struct s_mlx
{
	mlx_t			*mlx;
	t_raycast		*raycast;
	t_player		*player;
	t_render		*render;
	char			*map_path;
	int				**map;
	int32_t			win_w;
	int32_t			win_h;
	mlx_image_t		*image;
	mlx_texture_t	*texture;
	t_data			*d;
}	t_mlx;




/* --------------------- utils functions -------------------------------------*/
// free_utils.c
void	free_s(void *ptr);
void	free_d(char **ptr);
void	free_data(t_data *d);

// memory_utils.c
void	*safe_malloc(size_t size, t_data *d);

// error_utils.c
void	ftl_err(const char *msg, t_data *d);

/* --------------------- parse and map files ---------------------------------*/

// list_utils.c
void	ft_lst_print(t_list *list);

// map_checks.c
void	map_size(t_data *d);
void	is_map_symbols_correct(t_data *d);
void	is_map_closed(t_data *d);

// map_conversion.c
void	map_conversion(t_data *d);
void	find_player(char **arr, t_pos *pl_pos, char *player_dir);

// parsing.c
void	parse_cub_file(t_mlx *cub, t_data *d);
bool	is_map_line(void *content, bool *map_started);
void	d_extr(t_data *d);
void	parsing_process(t_mlx *cub, t_data *d);

// parsing_utils.c
char	*file_path_extractor(void *line, int start, t_data *d);
void	skip_empty_space(char *line, int *i, bool is_ascending);
void	color_extractor(char *line, unsigned int color[3], t_data *d);

bool	gnl_for_loop(int fd, char **line);
void	map_pos_checker(t_data *d);

//str_utils.c
char	*ft_strdup_w_o_nl(char *str, t_data *d);
void	ft_arr_print(char **arr);
char	*ft_safe_strdup_w_o_preceding_spaces(char *line, t_data *d);

// structs_init.c
void	structs_init(t_data *d);

//hooks.c
void	hook_key(mlx_key_d_t k, void *param);
void	hook_close(void *ptr);

//raycast.c
int	raycast_loop(t_mlx *cub, t_raycast *c, t_player *p);
int	raycast_init(t_mlx *cub);
#endif
