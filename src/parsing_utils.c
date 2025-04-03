/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:21:14 by milosz            #+#    #+#             */
/*   Updated: 2025/04/03 15:40:47 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will extract the file path from the line
 * 
 * @param content void* - the line content
 * @param start int - the starting index
 * @param d t_data* - the data structure
 * @return char* - the extracted file path
 */
char	*file_path_extractor(void *content, int start, t_data *d)
{
	int		i;
	int		j;
	char	*line;
	char	*path;

	line = (char *)content;
	i = start;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[j])
		j++;
	path = (char *)safe_malloc(sizeof(char) * (j - i + 1), d);
	j = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\n')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

/**
 * @brief This function will extract the file path from the line
 * 
 * @param line char * - the line content
 * @param i int * - the index to start from
 * @param is_ascending bool - true if we want to skip spaces in ascending order
 * @return void
 */
void	skip_empty_space(char *line, int *i, bool is_ascending)
{
	while (line[*i] == ' ')
	{
		if (is_ascending == true)
			(*i)++;
		else
			(*i)--;
	}
}

/**
 * @brief This function will extract the RGB d from the line
 * 
 * @param line char * - the line content
 * @param color unsigned int[3] - the array to store the RGB data
 * @param d t_data * - the data structure
 * @return void
 */
void	color_extractor(char *line, unsigned int color[3], t_data *d)
{
	int		i;
	int		j;
	int		len;
	char	temp_color[4];

	i = 2;
	j = 0;
	skip_empty_space(line, &i, true);
	while (line[i] && line[i] != '\n')
	{
		if (j > 2)
			ftl_err("incorrect RGB d input", d);
		len = 0;
		while (line[i] >= '0' && line[i] <= '9' && len < 3)
			temp_color[len++] = line[i++];
		temp_color[len] = '\0';
		color[j] = atoi(temp_color);
		if (len == 0 || len > 3 || color[j] > 255)
			ftl_err("incorrect RGB d input", d);
		if (line[i] == ',')
			i++;
		j++;
	}
	if (j != 3)
		ftl_err("incorrect RGB d input", d);
}

/**
 * @brief this is the extension of get_next_line function
 * that checks if the line is empty
 * 
 * @param fd int - file descriptor
 * @param line char** - pointer to the line
 */
bool	gnl_for_loop(int fd, char **line)
{
	char	*tmp;

	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (false);
	*line = ft_strdup(tmp);
	free(tmp);
	if (*line == NULL)
		ftl_err("in malloc", NULL);
	return (true);
}

/**
 * @brief This function will check if the map is in the correct position 
 * in the 'cub' file
 * 
 * @param d t_data* - the data structure
 * @return void
 */
void	map_pos_checker(t_data *d)
{
	int		is_map;
	int		isnt_map;
	t_list	*temp;
	char	*s_tmp;

	is_map = 0;
	isnt_map = 0;
	temp = d->ln_lst;
	while (temp)
	{
		s_tmp = ft_safe_strdup_w_o_preceding_spaces((char *)temp->content, d);
		if ((!ft_strncmp(s_tmp, "NO ", 3)) || (!ft_strncmp(s_tmp, "SO ", 3))
			|| (!ft_strncmp(s_tmp, "WE ", 3)) || (!ft_strncmp(s_tmp, "EA ", 3))
			|| (!ft_strncmp(s_tmp, "F ", 2)) || (!ft_strncmp(s_tmp, "C ", 2)))
			isnt_map++;
		if (s_tmp[0] == '1')
			is_map++;
		free(s_tmp);
		if (isnt_map != 6 && is_map > 0)
			ftl_err("in the 'cub' file - wrong d or map in the beginning",
				d);
		temp = temp->next;
	}
}
