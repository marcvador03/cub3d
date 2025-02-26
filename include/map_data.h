/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:54:18 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/26 18:41:17 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DATA_H
# define MAP_DATA_H

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


#endif
