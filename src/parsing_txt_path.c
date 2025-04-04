/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_txt_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:51:31 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/04 14:02:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will extract the file path from the line and check
 * if it exists
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
 * @brief This function will check if the file path exists
 * @param path char* - the file path
 * @return bool - true if the file path exists, false otherwise
 */
bool	is_path_existing(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

/**
 * @brief This function will check if the file paths exist
 * @param d t_data* - the data structure
 * @return void
 */
void	check_txt_file_existence(t_data *d)
{
	if (!is_path_existing(d->txs->no_tx) || !is_path_existing(d->txs->so_tx)
		|| !is_path_existing(d->txs->we_tx) || !is_path_existing(d->txs->ea_tx))
		ftl_err("Wrong texture filepath(s)", d);
}
