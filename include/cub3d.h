/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/08 15:24:15 by mpietrza         ###   ########.fr       */
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
# include "macros.h"
# include "data.h"

# define FALSE 0
# define TRUE 1

/* --------------------- utils functions -------------------------------------*/
// free_utils.c
void	free_s(void *ptr);
void	free_d(void **ptr);

// memory_utils.c
void	*safe_malloc(size_t size, t_data *d);

// exit_utils.c
void	ftl_err(const char *msg, t_data *d);
void	exit_normal(t_data *d);

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
void	map_size(t_data *d);
void	map_arr_to_int(t_data *d);

// parsing.c
void	parse_cub_file(t_data *d);
bool	is_map_line(void *content, bool *map_started);
void	data_extr(t_data *d);
void	parsing_process(t_data *d);

// parsing_txt_path.c
char	*file_path_extractor(void *line, int start, t_data *d);
bool	is_path_existing(char *path);
void	check_txt_file_existence(t_data *d);

// parsing_utils.c
void	skip_empty_space(char *line, int *i, bool is_ascending);
void	color_extractor(char *line, unsigned int color[3], t_data *d);
void	map_pos_checker(t_data *d);

// str_utils.c
char	*ft_strdup_w_o_nl(char *str, t_data *d);
void	ft_arr_print(char **arr);
char	*ft_safe_strdup_w_o_preceding_spaces(char *line, t_data *d);
bool	gnl_for_loop(int fd, char **line);
bool	ft_is_space_or_newline(char *str);

// structs_free.c
void	free_data(t_data *d);

// structs_init.c
void	structs_init(t_data *d);

/* --------------------- hooks ---------------------------------------------- */
// hooks.c
void	key_handler_press(struct mlx_key_data keydata, void *param);
void	key_handler_release(struct mlx_key_data keydata, void *param);
void	key_handler(struct mlx_key_data keydata, void *param);
void	hook_close(void *param);

/* --------------------- move ---------------------------------------------- */
// move_check_pos.c
bool	is_move_valid(t_data *d, t_player *p, double new_x, double new_y);

// move_player.c
void	move_player(void *param);

// player_direction.c
void	set_player_location_and_dir(t_data *d);

/* --------------------- raycasting -----------------------------------------*/

// raycast.c
int		raycast_loop(t_data *d, t_raycast *c, t_player *p);
int		raycast_init(t_data *d);

// render.c
int		render_init(t_data *d, t_render *r, t_raycast *c, int x);
#endif
