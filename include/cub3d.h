/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/04 19:11:24 by mpietrza         ###   ########.fr       */
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
# include "graphic_data.h"

typedef struct s_mlx
{
	mlx_t	*mlx;
	char	*map_path;
}	t_mlx;


/* --------------------- utils functions -------------------------------------*/
// free_utils.c
void	free_s(void *ptr);
void	free_d(char **ptr);

// memory_utils.c
void	*safe_malloc(size_t size);

// error_utils.c
void	ftl_err(const char *msg);

/* --------------------- parse and map files ---------------------------------*/
// flood_fill.c
char	**ft_arr_temp(t_map *map);
void	ft_flood_fill(char **tab, t_pos *size, t_pos *begin);

// list_utils.c
void	ft_lst_print(t_list *list);



// map_conversion.c
t_pos	*map_size(t_list *map_list);
char	**map_conversion(t_list *map_list, t_pos *map_size);
void	find_player(t_map *map);

// parsing.c
t_list	*parse_cub_file(t_mlx *cub);
t_list	*parse_cub_file(t_mlx *cub);
t_list	*data_extr(t_list *line_list, t_txtr_data *txtrs);
void	parsing_process(t_mlx *cub);

// parsing_utils.c
char	*file_path_extractor(void *line, int start);
void	skip_empty_space(char *line, int *i, bool incl_tab, bool is_ascending);
void	color_extractor(char *line, unsigned int color[3]);
bool	is_map_line(void *content);
bool	gnl_for_loop(int fd, char **line);

//str_utils.c
char	*ft_strdup_w_o_nl(char *str);

#endif
