/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:13:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/11 13:09:13 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**
 * @brief Free a single pointer
 * 
 * @param ptr 
 * @return void 
 */
void	free_s(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

/**
 * @brief Free a double pointer
 * 
 * @param ptr 
 * @return void 
 */
void	free_d(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		ptr[i++] = NULL;
	}
	free_s(ptr);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->txtrs)
		{
			free_s(data->txtrs->no_txtr);
			free_s(data->txtrs->so_txtr);
			free_s(data->txtrs->we_txtr);
			free_s(data->txtrs->ea_txtr);
			free_s(data->txtrs);
		}
		if (data->map)
		{
			free_d(data->map->arr);
			free_s(data->map->map_size);
			free_s(data->map->player_pos);
			free_s(data->map);
		}
		if (data->line_list)
			ft_lstclear(&data->line_list, free_s);
		if (data->map_list)
			ft_lstclear(&data->map_list, free_s);
		free_s(data);
	}
}
