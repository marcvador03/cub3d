/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/04 19:09:48 by mpietrza         ###   ########.fr       */
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
	printf("\nDebug: line is: %s", (char *)temp->content);
	if (is_map_line(temp->content))
	{
		printf("Debug: is_map_line\n");
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
	t_pos			*map_siz;

	g_data = (t_graph_data *)safe_malloc(sizeof(t_graph_data));
	printf("Debug 1: mallocked g_data\n");
	g_data->txtrs = (t_txtr_data *)safe_malloc(sizeof(t_txtr_data));
	printf("Debug 2: mallocked txtrs\n");
	line_list = parse_cub_file(cub);
	printf("Debug 3: parsed cub file\n");
	map_list = data_extr(line_list, g_data->txtrs);
	printf("Debug 3a: extracted list is:\n");
	ft_lstclear(&line_list, free_s);
	ft_lst_print(map_list);
	printf("Debug 4: extracted data\n");
	map_siz = map_size(map_list);
	printf("Debug 5: got map size\n");
	printf("Debug 5a: map size is: %d, %d\n", map_siz->x, map_siz->y);
	g_data->map->arr = map_conversion(map_list, map_siz);
	printf("Debug 5: converted map\n");
	find_player(g_data->map);
	printf("Debug 6: found player\n");
	ft_lstclear(&map_list, free_s);
	printf("Debug 7: cleared list\n");
}
