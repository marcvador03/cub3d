/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:13:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/28 17:22:20 by mpietrza         ###   ########.fr       */
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
void	free_d(void **ptr)
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
			free_s(d->mlx);
			d->mlx = NULL;
		}
		if (d->raycast)
			free_s(d->raycast);
		if (d->player)
			free_s(d->player);
		if (d->render)
			free_s(d->render);
		if (d->image)
			free_s(d->image);
		if (d->texture)
			free_s(d->texture);
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
			free_d((void **)d->map->arr);
			free_d((void **)d->map->i_map);
			free_s(d->map->map_size);
			free_s(d->map->pl_pos);
			free_s(d->map);
		}
		if (d->ln_lst)
			ft_lstclear(&d->ln_lst, free_s);
		if (d->map_lst)
			ft_lstclear(&d->map_lst, free_s);
		if (d->map_path)
			free_s(d->map_path);
		free_mlx_data(d);
		free_s(d);
	}
}
