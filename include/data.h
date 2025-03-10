/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:42:13 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/10 18:11:17 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_DATA_H
# define GRAPHIC_DATA_H

# include "cub3d.h"

typedef struct s_txtr_data
{
	char			*no_txtr;
	char			*so_txtr;
	char			*we_txtr;
	char			*ea_txtr;
	unsigned int	f_clr[3];
	unsigned int	c_clr[3];
}	t_txtr_data;

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
	t_pos	*player_pos;
	char	player_dir;
	int		x;
	int		y;
}		t_map;

typedef struct s_data
{
	t_txtr_data	*txtrs;
	t_map		*map;
	t_list		*line_list;
	t_list		*map_list;
}	t_data;

#endif
