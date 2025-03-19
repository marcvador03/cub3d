/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:01:55 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/19 16:57:07 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_init(t_mlx *cub, t_render *r, t_raycast *c, int x)
{
	int			y;
	uint32_t	color;
	
	if (cub->raycast->side_flag == TRUE)
		r->wallX = cub->player->posX + c->walldist * c->rayDirX;
	else
		r->wallX = cub->player->posY + c->walldist * c->rayDirY;
	r->wallX -= floor(r->wallX);
	r->pixelX = (int)(r->wallX * cub->texture->width);
	r->step = 1.0 * cub->texture->height / c->lineHeight;
 	r->pixel_pos = (c->wall_start - (cub->win_w / 2) + (c->lineHeight / 2)) * r->step;
	y = 0;
	while (y < cub->win_h)
	{
		if (y >= cub->raycast->wall_start && y <= cub->raycast->wall_end)
		{
			r->pixelY = (int) r->pixel_pos & (cub->texture->height - 1);
			r->pixel_pos += r->step;
			color = 		(cub->texture->pixels[cub->texture->height * r->pixelY * BPP + r->pixelX * BPP] << 24);
			color = color | (cub->texture->pixels[cub->texture->height * r->pixelY * BPP + r->pixelX * BPP + 1] << 16); 
			color = color | (cub->texture->pixels[cub->texture->height * r->pixelY * BPP + r->pixelX * BPP + 2] << 8); 
			color = color | (cub->texture->pixels[cub->texture->height * r->pixelY * BPP + r->pixelX * BPP + 3]);
			mlx_put_pixel(cub->image, cub->win_w - x, y++, color);
		}
		else if (y > cub->raycast->wall_end)
			mlx_put_pixel(cub->image, cub->win_w - x, y++, 0xFFFFFF);
		else if (y < cub->raycast->wall_start)
			mlx_put_pixel(cub->image, cub->win_w - x, y++, 0x00000000);
	}
	return (0);
}


