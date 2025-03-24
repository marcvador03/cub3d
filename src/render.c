/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:43 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/24 14:41:29 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgba(mlx_texture_t	*t, int p_pos)
{
	uint32_t	color;

	color = (t->pixels[t->height * p_pos] << 24);
	color = color | (t->pixels[t->height * p_pos + 1] << 16);
	color = color | (t->pixels[t->height * p_pos + 2] << 8);
	color = color | (t->pixels[t->height * p_pos + 3]);
	return (color);
}

static void	render_loop(t_data *d, t_render *r, int x)
{
	int			y;
	uint32_t	color;

	y = 0;
	while (y < d->win_h)
	{
		if (y >= d->raycast->wall_start && y <= d->raycast->wall_end)
		{
			r->pixel_y = (int) r->pixel_pos & (d->texture->height - 1);
			r->pixel_pos += r->step;
			color = get_rgba(d->texture, (r->pixel_y + r->pixel_x) * BPP);
			mlx_put_pixel(d->image, d->win_w - x, y++, color);
		}
		else if (y > d->raycast->wall_end)
			mlx_put_pixel(d->image, d->win_w - x, y++, *d->txs->f_clr);
		else if (y < d->raycast->wall_start)
			mlx_put_pixel(d->image, d->win_w - x, y++, *d->txs->c_clr);
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
