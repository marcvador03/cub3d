/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:43 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/25 16:43:58 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgba(mlx_texture_t	*t, int index)
{
    uint32_t color;

    if (index < 0 || index >= (int)(t->width * t->height))
    {
        fprintf(stderr, "Error: index out of bounds: %d\n", index);
        return 0; // Default color
    }
    color = (t->pixels[index * BPP] << 24);
    color |= (t->pixels[index * BPP + 1] << 16);
    color |= (t->pixels[index * BPP + 2] << 8);
    color |= (t->pixels[index * BPP + 3]);
    return color;
}

static void	render_loop(t_data *d, t_render *r, int x)
{
	int			y;
	uint32_t	color;
	uint32_t	height;
	

	y = 0;
	while (y < d->win_h)
	{
		if (y >= d->raycast->wall_start && y <= d->raycast->wall_end)
		{
			height = d->texture->height;
			r->pixel_y = (int) r->pixel_pos & (height- 1);
			r->pixel_pos += r->step;
			color = get_rgba(d->texture, (height * r->pixel_y + r->pixel_x));
			mlx_put_pixel(d->image, d->win_w - x - 1, y++, color);
		}
		else if (y > d->raycast->wall_end)
			mlx_put_pixel(d->image, d->win_w - x - 1, y++, *d->txs->f_clr);
		else if (y < d->raycast->wall_start)
			mlx_put_pixel(d->image, d->win_w - x - 1, y++, *d->txs->c_clr);
	}
	return ;
}

int	render_init(t_data *d, t_render *r, t_raycast *c, int x)
{
	int			tmp;

	if (d->raycast->side_flag == TRUE)
		r->wall_x = d->player->pos_x + c->walldist * c->raydir_x;
	else
		r->wall_x = d->player->pos_y + c->walldist * c->raydir_y;
	r->wall_x -= floor(r->wall_x);
	r->pixel_x = (int)(r->wall_x * d->texture->width);
	r->step = 1.0 * d->texture->height / c->lineheight;
	tmp = c->wall_start - (d->win_w / 2) + (c->lineheight / 2);
	r->pixel_pos = tmp * r->step;
	render_loop(d, r, x);
	return (0);
}
