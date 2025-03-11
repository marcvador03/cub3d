/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/11 13:05:43 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param cub
 * @param map
 * @return void 
 */
void	parse_cub_file(t_mlx *cub, t_data *data)
{
	int		fd;
	t_list	**head;
	t_list	*temp;
	char	*line;

	head = &data->line_list; // Store the address of the head pointer
	fd = open(cub->map_path, O_RDONLY);
	if (fd < 0)
		ftl_err("in opening file", data);
	while (gnl_for_loop(fd, &line))
	{
		temp = (t_list *)safe_malloc(sizeof(t_list), data);
		temp->content = line;
		temp->next = NULL;
		ft_lstadd_back(head, temp);
	}
	close(fd);
}

void	map_actions(t_list *temp, t_data *data) 
{
	t_list *new_node;
	t_list **map_head;
	
	map_head = &data->map_list;
	new_node = (t_list *)safe_malloc(sizeof(t_list), data);
	new_node->content = ft_strdup_w_o_nl((char *)temp->content, data);
	new_node->next = NULL;
	ft_lstadd_back(map_head, new_node);
}

/**
 * @brief This function will extract the data from the linked list
 * 
 * @param line_list
 * @param txtrs
 * @return void
 */
void	data_extr(t_data *data)
{
	t_list	*temp;

	temp = data->line_list;
	while (temp)
	{
		if (is_map_line(temp->content))
			map_actions(temp, data);
		else if (!ft_strncmp((char *)temp->content, "NO ", 3))
			data->txtrs->no_txtr = file_path_extractor(temp->content, 3, data);
		else if (!ft_strncmp((char *)temp->content, "SO ", 3))
			data->txtrs->so_txtr = file_path_extractor(temp->content, 3, data);
		else if (!ft_strncmp((char *)temp->content, "WE ", 3))
			data->txtrs->we_txtr = file_path_extractor(temp->content, 3, data);
		else if (!ft_strncmp((char *)temp->content, "EA ", 3))
			data->txtrs->ea_txtr = file_path_extractor(temp->content, 3, data);
		else if (!ft_strncmp((char *)temp->content, "F ", 2))
			color_extractor(temp->content, data->txtrs->f_clr, data);
		else if (!ft_strncmp((char *)temp->content, "C ", 2))
			color_extractor(temp->content, data->txtrs->c_clr, data);
		temp = temp->next;
	}
}



/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param cub
 * @param txtrs
 * @return void
 */
void	parsing_process(t_mlx *cub, t_data *data)
{
	structs_init(data);
	parse_cub_file(cub, data);
	map_pos_checker(data);
	data_extr(data);
	ft_lstclear(&data->line_list, free_s);
	map_size(data);
	map_conversion(data);
	ft_arr_print(data->map->arr);
	is_map_closed(data);
	is_map_symbols_correct(data);
	find_player(data->map->arr, data->map->player_pos,
		&data->map->player_dir);
	ft_lstclear(&data->map_list, free_s);
}
