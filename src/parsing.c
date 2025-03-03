/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/03 23:56:51 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param cub
 * @param map`
 * @return t_list* 
 */
t_list	*parse_cub_file(t_mlx *cub)
{
	int		fd;
	t_list	*map_list;
	t_list	*temp;
	char	*line;

	map_list = NULL;
	fd = open(cub->map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n in opening file");
		exit (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		temp = (t_list *)safe_malloc(sizeof(t_list));
		temp->line = line;
		temp->next = map_list;
		map_list = temp;
	}
	close(fd);
	return (map_list);
}

/**
 * @brief This function will extract the data from the linked list
 * 
 * @param line_list
 * @param txtrs
 * @return void
 */
void	data_extraction(t_list *line_list, t_txtr_data *txtrs)	
{
	t_list		*temp;
	t_list		*temp_prev;

	temp = line_list;
	while (temp)
	{
		if (!ft_strncmp(temp->line, "NO ", 3))
			txtrs->no_txtr = file_path_extractor(temp->line, 3);
		else if (!ft_strncmp(temp->line, "SO ", 3))
			txtrs->so_txtr = file_path_extractor(temp->line, 3);
		else if (!ft_strncmp(temp->line, "WE ", 3))
			txtrs->we_txtr = file_path_extractor(temp->line, 3);
		else if (!ft_strncmp(temp->line, "EA ", 3))
			txtrs->ea_txtr = file_path_extractor(temp->line, 3);
		else if (!ft_strncmp(temp->line, "F ", 2))
			color_extractor(temp->line, txtrs->f_clr);
		else if (!ft_strncmp(temp->line, "C ", 2))
			color_extractor(temp->line, txtrs->c_clr);
		else if (is_map_line(temp->line))
			temp = temp->next;
		temp_prev = temp;
		temp = temp->next;
		ft_lst_delprev(temp_prev, temp);
	}
}

/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param cub
 * @param txtrs
 * @return void
 */
void	parsing_process(t_mlx *cub)
{
	t_list			*map_list;
	t_graph_data	*g_data;

	g_data = (t_graph_data *)safe_malloc(sizeof(t_graph_data));
	g_data->txtrs = (t_txtr_data *)safe_malloc(sizeof(t_txtr_data));
	map_list = parse_cub_file(&cub);
	data_extraction(map_list, g_data->txtrs);
	g_data->map = map_conversion(map_list, map_size(map_list));
	find_player(g_data->map);
	ft_lstclear(&map_list, free_s);
}
