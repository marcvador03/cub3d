/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:13:46 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/20 16:07:18 by mpietrza         ###   ########.fr       */
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

static void	free_mlx(t_mlx *cub)
{
	if (cub)
	{
		if (cub->mlx && cub->mlx->window)
			mlx_close_window(cub->mlx);
		if (cub->image)
			mlx_delete_image(cub->mlx, cub->image);
		if (cub->mlx)
			free_s(cub->mlx);
		if (cub->raycast)
			free_s(cub->raycast);
		if (cub->player)
			free_s(cub->player);
		if (cub->render)
			free_s(cub->render);

		if (cub->map)
			free_d(cub->map);
		if (cub->image)
			free_s(cub->image);
		if (cub->texture)
			free_s(cub->texture);
		free_s(cub);
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
			free_d(d->map->arr);
			free_s(d->map->map_size);
			free_s(d->map->pl_pos);
			free_s(d->map);
		}
		if (d->ln_lst)
			ft_lstclear(&d->ln_lst, free_s);
		if (d->map_lst)
			ft_lstclear(&d->map_lst, free_s);
		if (d->cub)
			free_mlx(d->cub);
		if (d->map_path)
			free_s(d->map_path);
		free_s(d);
	}
}
