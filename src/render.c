/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:01:55 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/21 14:05:51 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_init(t_mlx *cub, t_render *r, t_raycast *c, int x)
{
	int			y;
	uint32_t	color;
	
	if (cub->raycast->side_flag == TRUE)
		r->wall_x = cub->player->pos_x + c->walldist * c->raydir_x;
	else
		r->wall_x = cub->player->pos_y + c->walldist * c->raydir_y;
	r->wall_x -= floor(r->wall_x);
	r->pixel_x = (int)(r->wall_x * cub->texture->width);
	r->step = 1.0 * cub->texture->height / c->lineheight;
 	r->pixel_pos = (c->wall_start - (cub->win_w / 2) + (c->lineheight / 2)) * r->step;
	y = 0;
	while (y < cub->win_h)
	{
		if (y >= cub->raycast->wall_start && y <= cub->raycast->wall_end)
		{
			r->pixel_y = (int) r->pixel_pos & (cub->texture->height - 1);
			r->pixel_pos += r->step;
			color = 		(cub->texture->pixels[cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP] << 24);
			color = color | (cub->texture->pixels[cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP + 1] << 16); 
			color = color | (cub->texture->pixels[cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP + 2] << 8); 
			color = color | (cub->texture->pixels[cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP + 3]);
			mlx_put_pixel(cub->image, cub->win_w - x, y++, color);
		}
		else if (y > cub->raycast->wall_end)
			mlx_put_pixel(cub->image, cub->win_w - x, y++, *cub->d->txs->f_clr);
		else if (y < cub->raycast->wall_start)
			mlx_put_pixel(cub->image, cub->win_w - x, y++, *cub->d->txs->c_clr);
	}
	return (0);
}


