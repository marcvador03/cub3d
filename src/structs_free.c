/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:25:17 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/03 15:32:41 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Free the lists
 * 
 * @param d t_data *
 * @return void
 */
static void	free_lists(t_data *d)
{
	if (d->ln_lst)
		ft_lstclear(&d->ln_lst, free_s);
	if (d->map_lst)
		ft_lstclear(&d->map_lst, free_s);
}

/**
 * @brief Free the strings with texture file names
 * 
 * @param d t_data *
 * @return void 
 */
static void	free_textures(t_data *d)
{
	if (d->texture_no)
	{
		mlx_delete_texture(d->texture_no);
		d->texture_no = NULL;
	}
	if (d->texture_so)
	{
		mlx_delete_texture(d->texture_so);
		d->texture_so = NULL;
	}
	if (d->texture_we)
	{
		mlx_delete_texture(d->texture_we);
		d->texture_we = NULL;
	}
	if (d->texture_ea)
	{
		mlx_delete_texture(d->texture_ea);
		d->texture_ea = NULL;
	}
}

/**
 * @brief Free the mlx data
 * 
 * @param d t_data *
 * @return void 
 */
static void	free_mlx_data(t_data *d)
{
	if (d)
	{
		if (d->mlx && d->mlx->window)
			mlx_close_window(d->mlx);
		if (d->image)
			mlx_delete_image(d->mlx, d->image);
		if (d->mlx)
		{
			mlx_terminate(d->mlx);
			d->mlx = NULL;
		}
		if (d->raycast)
			free_s(d->raycast);
		if (d->player)
			free_s(d->player);
		if (d->render)
			free_s(d->render);
		if (d->image)
			d->image = NULL;
		free_textures(d);
	}
}

/**
 * @brief Free the d structure
 * 
 * @param d t_data *
 * @return void 
 */
void	free_data(t_data *d)
{
	if (d)
	{
		if (d->txs)
		{
			free_s(d->txs->no_tx);
			free_s(d->txs->so_tx);
			free_s(d->txs->we_tx);
			free_s(d->txs->ea_tx);
			free_s(d->txs);
		}
		if (d->map)
		{
			free_d((void **)d->map->i_map);
			free_d((void **)d->map->arr);
			free_s(d->map->map_size);
			free_s(d->map->pl_pos);
			free_s(d->map);
		}
		free_lists(d);
		if (d->map_path)
			free_s(d->map_path);
		free_mlx_data(d);
		free_s(d);
	}
}
