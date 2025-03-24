/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:59:20 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/20 15:52:39 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**
 * @brief This function will initialize the structs
 * 
 * @param d t_data*
 * @return void
 */
void	structs_init(t_data *d)
{
	d->txs = (t_gr_data *)safe_malloc(sizeof(t_gr_data), d);
	d->txs->no_tx = NULL;
	d->txs->so_tx = NULL;
	d->txs->we_tx = NULL;
	d->txs->ea_tx = NULL;
	d->map = (t_map *)safe_malloc(sizeof(t_map), d);
	d->map->pl_pos = (t_pos *)safe_malloc(sizeof(t_pos), d);
	d->map->map_size = (t_pos *)safe_malloc(sizeof(t_pos), d);
	d->map->arr = NULL;
	d->ln_lst = NULL;
	d->map_lst = NULL;
	d->cub = (t_mlx *)safe_malloc(sizeof(t_mlx), d);
	d->pl_mv = RESET;
	d->pl_rotate = RESET;
}
