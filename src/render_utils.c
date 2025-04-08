/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:02:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/08 16:03:53 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will get the texture based on the direction
 * 
 * @param d t_data* - the data structure
 * @return mlx_texture_t* - the texture
 */

mlx_texture_t	*get_texture_direction(t_data *d)
{
	mlx_texture_t	*tex;

	if (d->raycast->side_flag == 0)
	{
		if (d->raycast->raydir_x >= 0)
			tex = d->texture_ea;
		else
			tex = d->texture_we;
	}
	else
	{
		if (d->raycast->raydir_y > 0)
			tex = d->texture_no;
		else
			tex = d->texture_so;
	}
	return (tex);
}
