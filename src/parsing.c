/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:59:56 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/09 13:59:57 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param d t_data* - the data structure
 * @return void 
 */
void	parse_cub_file(t_data *d)
{
	int		fd;
	t_list	**head;
	t_list	*temp;
	char	*line;

	head = &d->ln_lst;
	if (check_cub_file_ext(d->map_path) == -1)
		ftl_err("map path invalid or extension incorrect", d);
	fd = open(d->map_path, O_RDONLY);
	if (fd < 0)
		ftl_err("in opening file", d);
	while (gnl_for_loop(fd, &line))
	{
		temp = (t_list *)safe_malloc(sizeof(t_list), d);
		temp->content = ft_strdup(line);
		if (!temp->content)
			ftl_err("in malloc", d);
		temp->next = NULL;
		ft_lstadd_back(head, temp);
		free(line);
		line = NULL;
	}
	close(fd);
}

/**
 * @brief Adds a new node to the map linked list if the map has started.
 *
 * This function checks if the map parsing has started. If it has, it creates
 * a new node for the map linked list, duplicates the content of the current
 * node without the newline character, and appends the new node to the end of
 * the map linked list.
 *
 * @param temp t_list* Pointer to the current node in the input 
 * 		  list being processed.
 * @param d  t_data* Pointer to the main data structure containing the map
 * 			 linked list.
 * @param map_started bool*  Pointer to a boolean indicating whether
 * 		  the map parsing has started.
 *
 * @note The function uses `safe_malloc` to allocate memory and 
 * 		 `ft_strdup_w_o_nl` to duplicate the content of the current node
 * 		 without the newline character.
 *       It also uses `ft_lstadd_back` to append the new node to the linked list.
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
 * @param content void* - the line to check
 * @param map_started bool* - a pointer to a boolean that indicates 
 * 		  if the map has started
 * @return bool  - true if the line is a map line, false otherwise
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
 * @param d t_data* - the data structure
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
		else if (!ft_is_space_or_newline((char *)temp->content))
			ftl_err("incorrect line in cub file", d);
		temp = temp->next;
	}
}

/**
 * @brief This is the main function for parsing the cub file
 * 		  incorporating all the parsing functions
 * 
 * @param d t_data* - the data structure
 * @return void
 */
void	parsing_process(t_data *d)
{
	parse_cub_file(d);
	map_pos_checker(d);
	data_extr(d);
	is_correct_num_of_args(d);
	check_txt_file_existence(d);
	map_size(d);
	map_conversion(d);
	is_map_closed(d);
	is_map_symbols_correct(d);
	find_player(d->map->arr, d->map->pl_pos, &d->map->player_dir);
	map_arr_to_int(d);
}
