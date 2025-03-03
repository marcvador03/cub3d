/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/03 23:56:36 by milosz           ###   ########.fr       */
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
void	ftl_err(char msg[1024]);

/* --------------------- parse and map files ---------------------------------*/
// flood_fill.c
char	**ft_arr_temp(t_map *map);
void	ft_flood_fill(char **tab, t_pos *size, t_pos *begin);

// map_conversion.c
t_pos	*map_size(t_list *map_list);
char	**map_conversion(t_list *map_list, t_pos *map_size);
void	find_player(t_map *map);

// parsing.c
t_list	*parse_cub_file(t_mlx *cub);
void	data_extraction(t_list *line_list, t_txtr_data *txtrs);
void	parsing_process(t_mlx *cub);

// parsing_utils.c
char	*file_path_extractor(char *line, int start);
void	skip_empty_space(char *line, int *i, bool incl_tab, bool is_ascending);
void	color_extractor(char *line, int color[3]);
bool	is_map_line(char *line);
void	ft_lst_delprev(t_list *prev, t_list *current);


#endif
