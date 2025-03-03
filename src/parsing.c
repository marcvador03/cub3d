/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/03 17:10:27 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will parse the map file and store it in a linked list
 * 
 * @param cub
 * @param map
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

char	*file_path_extractor(char *line, int start)
{
	int		i;
	int		j;
	char	*path;

	i = start;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j])
		j++;
	path = (char *)safe_malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

static void	skip_empty_space(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		*i++;
}

void	color_extractor(char *line, int color[3])
{
	int		i;
	int		j;
	int		len;
	char	temp_color[4];
	
	i = 2;
	j = 0;
	skip_empty_space(line, &i);
	while (line[i] && line[i] != '\n')
	{
		if (j > 2)
			ftl_err("incorrect RGB data input");
		len = 0;
		while (line[i] >= '0' && line[i] <= '9' && len < 3)
			temp_color[len++] = line[i++];
		color[j] = atoi(temp_color[j]);
		if (len == 0 || len > 3)
			ftl_err("incorrect RGB data input");
		temp_color[len] = '\0';
		if (line[i] == ',')
			i++; //to skip the ',' in RGB
		j++;
	}
	if (j != 3)
		ftl_err("incorrect RGB data input");
}


static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

static void	ft_lst_delprev(t_list *prev, t_list *current)
{
	prev->next = current->next;
	free(current->line);
	free(current);
}
/*
*/
void	data_extraction(t_list *line_list)
{
	t_list		*temp;
	t_list		*temp_prev;
	t_txtr_data	*txtrs;

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

void	parsing_process(t_mlx *cub, t_txtr_data *txtrs)
{
	t_list	*map_list;

	map_list = parse_cub_file(&cub);
	// map_conversion(map_list, map_size(map_list));
}