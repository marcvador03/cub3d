/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:21:14 by milosz            #+#    #+#             */
/*   Updated: 2025/03/11 12:50:16 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will extract the file path from the line
 * 
 * @param content void*
 * @param start int
 * @return char*
 */
char	*file_path_extractor(void *content, int start, t_data *data)
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
	path = (char *)safe_malloc(sizeof(char) * (j - i + 1), data);
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
 * @param line char *
 * @param i int *
 * @param is_ascending bool
 * @return char* 
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
 * @brief This function will extract the RGB data from the line
 * 
 * @param line char *
 * @param color unsigned int[3]
 * @return void
 */
void	color_extractor(char *line, unsigned int color[3], t_data *data)
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
			ftl_err("incorrect RGB data input", data);
		len = 0;
		while (line[i] >= '0' && line[i] <= '9' && len < 3)
			temp_color[len++] = line[i++];
		temp_color[len] = '\0';
		color[j] = atoi(temp_color);
		if (len == 0 || len > 3 || color[j] > 255)
			ftl_err("incorrect RGB data input", data);
		if (line[i] == ',')
			i++; //to skip the ',' in RGB
		j++;
	}
	if (j != 3)
		ftl_err("incorrect RGB data input", data);
}

/**
 * @brief This function will check if the line is a map line
 * 
 * @param line
 * @return bool 
 */
bool	is_map_line(void *content)
{
	int		i;
	char	*line;

	line = (char *)content;
	i = 0;
	while (line[i + 1])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (false);
		i++;
	}
	if (line[i] && line[i] != '1' && line[i] != ' ' && line[i] != '\n')
		return (false);
	return (true);
}

bool	gnl_for_loop(int fd, char **line)
{
	*line = get_next_line(fd);
	if (*line == NULL)
		return (false);
	return (true);
}

void	map_pos_checker(t_data *data)
{
	int		is_map;
	int		isnt_map;
	t_list	*temp;
	char	*s_tmp;

	is_map = 0;
	isnt_map = 0;
	temp = data->line_list;
	while (temp)
	{
		s_tmp = ft_safe_strdup_w_o_leading_spaces((char *)temp->content, data);
		if ((!ft_strncmp(s_tmp, "NO ", 3)) || (!ft_strncmp(s_tmp, "SO ", 3))
			|| (!ft_strncmp(s_tmp, "WE ", 3)) || (!ft_strncmp(s_tmp, "EA ", 3))
			|| (!ft_strncmp(s_tmp, "F ", 2)) || (!ft_strncmp(s_tmp, "C ", 2)))
			isnt_map++;
		if (s_tmp[0] == '1')
			is_map++;
		free(s_tmp);
		if (isnt_map != 6 && is_map > 0)
			ftl_err("in the 'cub' file - wrong data or map in the beginning",
				data);
		temp = temp->next;
	}
}
