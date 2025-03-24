/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:43 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/24 13:13:19 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_init(t_data *d, t_render *r, t_raycast *c, int x)
{
	int			y;
	uint32_t	color;
	
	if (d->cub->raycast->side_flag == TRUE)
		r->wall_x = d->cub->player->pos_x + c->walldist * c->raydir_x;
	else
		r->wall_x = d->cub->player->pos_y + c->walldist * c->raydir_y;
	r->wall_x -= floor(r->wall_x);
	r->pixel_x = (int)(r->wall_x * d->cub->texture->width);
	r->step = 1.0 * d->cub->texture->height / c->lineheight;
 	r->pixel_pos = (c->wall_start - (d->cub->win_w / 2) + (c->lineheight / 2)) * r->step;
	y = 0;
	while (y < d->cub->win_h)
	{
		if (y >= d->cub->raycast->wall_start && y <= d->cub->raycast->wall_end)
		{
			r->pixel_y = (int) r->pixel_pos & (d->cub->texture->height - 1);
			r->pixel_pos += r->step;
			color = 		(d->cub->texture->pixels[d->cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP] << 24);
			color = color | (d->cub->texture->pixels[d->cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP + 1] << 16); 
			color = color | (d->cub->texture->pixels[d->cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP + 2] << 8); 
			color = color | (d->cub->texture->pixels[d->cub->texture->height * r->pixel_y * BPP + r->pixel_x * BPP + 3]);
			mlx_put_pixel(d->cub->image, d->cub->win_w - 1 - x, y++, color);
		}
		else if (y > d->cub->raycast->wall_end)
			mlx_put_pixel(d->cub->image, d->cub->win_w - 1- x, y++, *d->txs->f_clr);
		else if (y < d->cub->raycast->wall_start)
			mlx_put_pixel(d->cub->image, d->cub->win_w - 1 - x, y++, *d->txs->c_clr);
	}
	return (0);
}


