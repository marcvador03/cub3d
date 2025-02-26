/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/26 18:40:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*parse_map(t_mlx *cub, t_map *map)
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
