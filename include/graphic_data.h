/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:42:13 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/03 23:56:54 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_DATA_H
# define GRAPHIC_DATA_H

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

/* struct for list to store the lines read from the file*/
typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}				t_list;

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

typedef struct s_graph_data
{
	t_txtr_data	*txtrs;
	t_map		*map;
}	t_graph_data;
#endif
