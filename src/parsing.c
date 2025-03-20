/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/20 16:06:15 by mpietrza         ###   ########.fr       */
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
void	parse_cub_file(t_data *d)
{
	int		fd;
	t_list	**head;
	t_list	*temp;
	char	*line;

	head = &d->ln_lst; // Store the address of the head pointer
	if (!d->map_path)
		ftl_err("in map path", d);
	printf("Debug: map path: %s\n", d->map_path);
	fd = open(d->map_path, O_RDONLY);
	if (fd < 0)
		ftl_err("in opening file", d);
	while (gnl_for_loop(fd, &line))
	{
		temp = (t_list *)safe_malloc(sizeof(t_list), d);
		temp->content = line;
		temp->next = NULL;
		ft_lstadd_back(head, temp);
	}
	close(fd);
}

/**
 * @brief This function will check if the line is a map line
 * then store it in the map linked list
 * 
 * @param temp t_list*
 * @param d t_data*
 * @param map_started bool*
 * @return void
 */
static void	map_actions(t_list *temp, t_data *d, bool *map_started)
{
	t_list	*new_node;
	t_list	**map_head;

	if (!*map_started)
		return ;
	map_head = &d->map_lst;
	new_node = (t_list *)safe_malloc(sizeof(t_list), d);
	new_node->content = ft_strdup_w_o_nl((char *)temp->content, d);
	new_node->next = NULL;
	ft_lstadd_back(map_head, new_node);
}

/**
 * @brief This function will check if the line is a map line
 * 
 * @param line
 * @return bool 
 */
bool	is_map_line(void *content, bool *map_started)
{
	int		i;
	char	*line;

	line = (char *)content;
	i = 0;
	while (line[i + 1])
	{
		if (line[i] == '1' && !*map_started)
			*map_started = true;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (false);
		i++;
	}
	if (line[i] && line[i] != '1' && line[i] != ' ' && line[i] != '\n')
		return (false);
	return (true);
}

/**
 * @brief This function will extract the d from the linked list
 * 
 * @param d
 * @return void
 */
void	data_extr(t_data *d)
{
	t_list	*temp;
	bool	map_started;

	map_started = false;
	temp = d->ln_lst;
	while (temp)
	{
		if (is_map_line(temp->content, &map_started))
			map_actions(temp, d, &map_started);
		else if (!ft_strncmp((char *)temp->content, "NO ", 3))
			d->txs->no_tx = file_path_extractor(temp->content, 3, d);
		else if (!ft_strncmp((char *)temp->content, "SO ", 3))
			d->txs->so_tx = file_path_extractor(temp->content, 3, d);
		else if (!ft_strncmp((char *)temp->content, "WE ", 3))
			d->txs->we_tx = file_path_extractor(temp->content, 3, d);
		else if (!ft_strncmp((char *)temp->content, "EA ", 3))
			d->txs->ea_tx = file_path_extractor(temp->content, 3, d);
		else if (!ft_strncmp((char *)temp->content, "F ", 2))
			color_extractor(temp->content, d->txs->f_clr, d);
		else if (!ft_strncmp((char *)temp->content, "C ", 2))
			color_extractor(temp->content, d->txs->c_clr, d);
		temp = temp->next;
	}
}

/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param cub
 * @param d
 * @return void
 */
void	parsing_process(t_data *d)
{
	structs_init(d);
	parse_cub_file(d);
	map_pos_checker(d);
	data_extr(d);
	ft_lstclear(&d->ln_lst, free_s);
	map_size(d);
	map_conversion(d);
	//ft_arr_print(d->map->arr);
	is_map_closed(d);
	is_map_symbols_correct(d);
	find_player(d->map->arr, d->map->pl_pos, &d->map->player_dir);
	ft_lstclear(&d->map_lst, free_s);
}
