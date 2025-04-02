/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:13:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/02 14:03:33 by milosz           ###   ########.fr       */
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
	if (!ptr || !*ptr) 
		return ;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free_s(ptr);
	ptr = NULL;
}

static void free_textures(t_data *d)
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

/*static void free_imap(t_data *d)
{
	int	i;

	i = 0;
	while (d->map->i_map[i] < d->map->map_size->y - 1)
	{
		free(d->map->i_map[i]);
		i++;
	}
	free_s(d->map->i_map);
}*/

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
			free_d((void**)d->map->i_map);
			free_d((void**)d->map->arr);
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
