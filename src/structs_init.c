/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:59:20 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/08 10:52:06 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	structs_init2(t_data *d)
{
	d->ln_lst = NULL;
	d->map_lst = NULL;
	d->pl_mv = RESET;
	d->pl_rotate = RESET;
	d->map_path = NULL;
	d->frame_number = 0;
	d->start = 0;
}

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
	d->mlx = NULL;
	d->raycast = NULL;
	d->player = NULL;
	d->render = NULL;
	d->win_w = RESET;
	d->win_h = RESET;
	d->aspect_ratio = RESET;
	d->image = NULL;
	d->texture_no = NULL;
	d->texture_so = NULL;
	d->texture_we = NULL;
	d->texture_ea = NULL;
	d->map = (t_map *)safe_malloc(sizeof(t_map), d);
	d->map->pl_pos = (t_pos *)safe_malloc(sizeof(t_pos), d);
	d->map->map_size = (t_pos *)safe_malloc(sizeof(t_pos), d);
	d->map->arr = NULL;
	d->map->i_map = NULL;
	d->map->player_dir = RESET;
	structs_init2(d);
}
