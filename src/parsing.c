/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/28 14:34:54 by mpietrza         ###   ########.fr       */
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

void	color_extractor(char *line, int color[3])
{
	int		i;
	int		j;
	int		len;
	char	temp_color[4];
	
	i = 2;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i] && line[i] != '\n')
	{
		if (j > 2)
			ftl_err("incorrect RGB data input");
		len = 0;
		while (line[i] >= '0' && line[i] <= '9')
		{
			len++;
			if (len > 3)
				ftl_err("incorrect RGB data input");
			temp_color[j] = line[i++];
		}
		color[j] = atoi(temp_color[j]);
		if (line[i] == ',')
			i++; //to skip the ',' in RGB
		j++;
	}
	if (j != 3)
		ftl_err("incorrect RGB data input");
}
/*
void	color_extractor(char *line, int color[3])
{
    int		i;
    int		j;
    int		len;
    char	temp_color[4]; // Increased size to hold up to 3 digits and a null terminator
    
    i = 2;
    j = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    while (line[i] && line[i] != '\n')
    {
        if (j > 2)
            ftl_err("incorrect RGB data input");
        len = 0;
        while (line[i] >= '0' && line[i] <= '9' && len < 3)
        {
            temp_color[len++] = line[i++];
        }
        if (len == 0 || len > 3)
            ftl_err("incorrect RGB data input");
        temp_color[len] = '\0'; // Null-terminate the string
        color[j] = atoi(temp_color);
        if (line[i] == ',')
            i++; // Skip the ',' in RGB
        j++;
    }
    if (j != 3)
        ftl_err("incorrect RGB data input");
}
*/
void	data_extraction(t_list *line_list)
{
	t_list		*temp;
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
			txtrs->f_clr = color_extractor(temp->line, 2);
		else if (!ft_strncmp(temp->line, "C ", 2))
			txtrs->c_clr = color_extractor(temp->line, 2);

		else
		if (temp->line[0] == 'N' && temp->line[1] == 'O')
			
		else if (temp->line[0] == 'S' && temp->line[1] == 'O')
			// txtr_extraction(temp->line);
		else if (temp->line[0] == 'W' && temp->line[1] == 'E')
			// txtr_extraction(temp->line);
		else if (temp->line[0] == 'E' && temp->line[1] == 'A')
			// txtr_extraction(temp->line);
		else if (temp->line[0] == 'F')
			// color_extraction(temp->line);
		else if (temp->line[0] == 'C')
			// color_extraction(temp->line);
		temp = temp->next;
	}
}

void	parsing_process(t_mlx *cub, t_txtr_data *txtrs)
{
	t_list	*map_list;

	map_list = parse_cub_file(&cub);
	// map_conversion(map_list, map_size(map_list));
}