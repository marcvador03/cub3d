/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/10 18:40:16 by mpietrza         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../libft/getnextline/get_next_line.h"
# include "../mlx42/include/MLX42/MLX42.h"

# include "macros.h"
# include "data.h"

typedef struct s_mlx
{
	mlx_t	*mlx;
	char	*map_path;
}	t_mlx;


/* --------------------- utils functions -------------------------------------*/
// free_utils.c
void	free_s(void *ptr);
void	free_d(char **ptr);
void	free_data(t_data *data);

// memory_utils.c
void	*safe_malloc(size_t size, t_data *data);

// error_utils.c
void	ftl_err(const char *msg, t_data *data);

/* --------------------- parse and map files ---------------------------------*/

// list_utils.c
void	ft_lst_print(t_list *list);

// map_checks.c
void	map_size(t_data *data);
void	is_map_symbols_correct(t_data *data);
void	is_map_closed(t_data *data);

// map_conversion.c
void	map_conversion(t_data *data);
void	find_player(char **arr , t_pos *player_pos, char *player_dir);

// parsing.c
void	parse_cub_file(t_mlx *cub, t_data *data);
void	data_extr(t_data *data);
void	parsing_process(t_mlx *cub, t_data *data);

// parsing_utils.c
char	*file_path_extractor(void *line, int start, t_data *data);
void	skip_empty_space(char *line, int *i, bool is_ascending);
void	color_extractor(char *line, unsigned int color[3], t_data *data);
bool	is_map_line(void *content);
bool	gnl_for_loop(int fd, char **line);
void	map_pos_checker(t_data *data);

//str_utils.c
char	*ft_strdup_w_o_nl(char *str, t_data *data);
void	ft_arr_print(char **arr);
char	*ft_safe_strdup_w_o_leading_spaces(char *line, t_data *data);

#endif
