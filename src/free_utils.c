/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:13:46 by mfleury           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/31 18:58:14 by mfleury          ###   ########.fr       */
=======
/*   Updated: 2025/03/31 18:57:17 by milosz           ###   ########.fr       */
>>>>>>> 124cb1d539b10d1e5326a32408078ee0261be383
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
//			free_s(d->mlx);
			d->mlx = NULL;
		}
		if (d->raycast)
			free_s(d->raycast);
		if (d->player)
			free_s(d->player);
		if (d->render)
			free_s(d->render);
		if (d->image)
<<<<<<< HEAD
			free_s(d->image);
		if (d->texture_no)
			free_s(d->texture_no);
=======
//			free_s(d->image);
			d->image = NULL;
		if (d->texture)
		{
			mlx_delete_texture(d->texture);
			d->texture = NULL;
		}
>>>>>>> 124cb1d539b10d1e5326a32408078ee0261be383
	}
}

static void free_imap(t_data *d)
{
	int	i;

	i = 0;
	while (d->map->i_map[i])
	{
		free(d->map->i_map[i]);
		i++;
	}
	free_s(d->map->i_map);
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
			free_imap(d);
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
