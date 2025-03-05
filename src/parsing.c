/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/05 15:31:21 by mpietrza         ###   ########.fr       */
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
t_list *parse_cub_file(t_mlx *cub)
{
	int		fd;
	t_list	*map_list;
	t_list	**head;
	t_list	*temp;
	char	*line;

	map_list = NULL;
	head = &map_list; // Store the address of the head pointer
	fd = open(cub->map_path, O_RDONLY);
	if (fd < 0)
		ftl_err("in opening file");
	while (gnl_for_loop(fd, &line))
	{
		temp = (t_list *)safe_malloc(sizeof(t_list));
		temp->content = line;
		temp->next = NULL;
		ft_lstadd_back(head, temp);
	}
	close(fd);
	return (map_list);
}

void map_actions(t_list *temp, t_list **map_head) 
{
	if (is_map_line(temp->content))
	{
		t_list *new_node = (t_list *)safe_malloc(sizeof(t_list));
		new_node->content = ft_strdup_w_o_nl((char *)temp->content);
		new_node->next = NULL;
		ft_lstadd_back(map_head, new_node);
	}
}

/**
 * @brief This function will extract the data from the linked list
 * 
 * @param line_list
 * @param txtrs
 * @return void
 */
t_list *data_extr(t_list *line_list, t_txtr_data *txtrs)
{
	t_list *temp;
	t_list *map_list;

	temp = line_list;
	map_list = NULL;
	while (temp)
	{
		if (is_map_line(temp->content))
			map_actions(temp, &map_list);
		else if (!ft_strncmp((char *)temp->content, "NO ", 3))
			txtrs->no_txtr = file_path_extractor(temp->content, 3);
		else if (!ft_strncmp((char *)temp->content, "SO ", 3))
			txtrs->so_txtr = file_path_extractor(temp->content, 3);
		else if (!ft_strncmp((char *)temp->content, "WE ", 3))
			txtrs->we_txtr = file_path_extractor(temp->content, 3);
		else if (!ft_strncmp((char *)temp->content, "EA ", 3))
			txtrs->ea_txtr = file_path_extractor(temp->content, 3);
		else if (!ft_strncmp((char *)temp->content, "F ", 2))
			color_extractor(temp->content, txtrs->f_clr);
		else if (!ft_strncmp((char *)temp->content, "C ", 2))
			color_extractor(temp->content, txtrs->c_clr);
		temp = temp->next;
	}
	return (map_list);
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
	t_list			*line_list;
	t_list			*map_list;
	t_graph_data	*g_data;

	g_data = (t_graph_data *)safe_malloc(sizeof(t_graph_data));
	g_data->txtrs = (t_txtr_data *)safe_malloc(sizeof(t_txtr_data));
	g_data->map = (t_map *)safe_malloc(sizeof(t_map));
	g_data->map->player_pos = (t_pos *)safe_malloc(sizeof(t_pos));
	line_list = parse_cub_file(cub);
	map_pos_checker(line_list);
	map_list = data_extr(line_list, g_data->txtrs);
	ft_lstclear(&line_list, free_s);
	g_data->map->arr = map_conversion(map_list, map_size(map_list));
	find_player(g_data->map);
	ft_lstclear(&map_list, free_s);
}
