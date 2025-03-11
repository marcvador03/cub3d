/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:59:20 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/11 14:56:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**
 * @brief This function will initialize the structs
 * 
 * @param data t_data*
 * @return void
 */
void	structs_init(t_data *data)
{
	data->txtrs = (t_txtr_data *)safe_malloc(sizeof(t_txtr_data), data);
	data->txtrs->no_txtr = NULL;
	data->txtrs->so_txtr = NULL;
	data->txtrs->we_txtr = NULL;
	data->txtrs->ea_txtr = NULL;
	data->map = (t_map *)safe_malloc(sizeof(t_map), data);
	data->map->player_pos = (t_pos *)safe_malloc(sizeof(t_pos), data);
	data->map->map_size = (t_pos *)safe_malloc(sizeof(t_pos), data);
	data->map->arr = NULL;
	data->line_list = NULL;
	data->map_list = NULL;
}
