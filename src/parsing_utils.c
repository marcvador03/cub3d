/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:21:14 by milosz            #+#    #+#             */
/*   Updated: 2025/03/03 23:30:07 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will extract the file path from the line
 * 
 * @param line
 * @param start
 * @return char*
 */
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

/**
 * @brief This function will extract the file path from the line
 * 
 * @param line
 * @param start
 * @return char* 
 */
void	skip_empty_space(char *line, int *i, bool incl_tab, bool is_ascending)
{
	if (incl_tab == true)
	{
		while (line[*i] == ' ' || line[*i] == '\t')
		{	
			if (is_ascending == true)
				*i++;
			else
				*i--;
		}
	}
	else
	{
		while (line[*i] == ' ')
		{
			if (is_ascending == true)
				*i++;
			else
				*i--;
		}
	}
}

/**
 * @brief This function will extract the RGB data from the line
 * 
 * @param line
 * @param color
 * @return void
 */
void	color_extractor(char *line, int color[3])
{
	int		i;
	int		j;
	int		len;
	char	temp_color[4];
	
	i = 2;
	j = 0;
	skip_empty_space(line, &i, true, true);
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

/**
 * @brief This function will check if the line is a map line
 * 
 * @param line
 * @return bool 
 */
bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	skip_empty_space(line, i, false, true);
	while (line[i + 1])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'E' && line[i] != 'W' && line[i++] != ' ')
			return (false);
	}
	if (line[i] != '1' && line[i] && line[i] != ' ' && line[i] != '\n')
		return (false);
	return (true);
}

/**
 * @brief This function will delete the previous node in the linked list
 * 
 * @param prev
 * @param current
 * @return void
 */
void	ft_lst_delprev(t_list *prev, t_list *current)
{
	prev->next = current->next;
	free(current->line);
	free(current);
}