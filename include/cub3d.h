/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/27 16:58:23 by mpietrza         ###   ########.fr       */
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

# include "map_data.h"
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

/* --------------------- parse and map files ---------------------------------*/
// flood_fill.c
char	**ft_arr_temp(t_map *map);
void	ft_flood_fill(char **tab, t_pos *size, t_pos *begin);

// map_conversion.c
t_pos	*map_size(t_list *map_list);
char	**map_conversion(t_list *map_list, t_pos *map_size);

// parsing.c
void	parse_cub_file(t_mlx *cub);
void	parsing_process(t_mlx *cub, t_txtr_data txtrs);


#endif
