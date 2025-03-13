/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:50:03 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/13 18:46:20 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "cub3d.h"

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
	char	**arr;
	t_pos	*map_size;
	t_pos	*pl_pos;
	char	player_dir;
	int		x;
	int		y;
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
	int			pl_move;
	int			pl_rotate;
}	t_data;

#endif
