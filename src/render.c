/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:43 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/02 15:14:24 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgba(mlx_texture_t	*t, int index)
{
	uint32_t	color;

	if (index < 0 || index >= (int)(t->width * t->height))
	{
		fprintf(stderr, "Error: index out of bounds: %d\n", index);
		return (-1); // Default color
	}
	color = (t->pixels[index * BPP] << 24);
	color |= (t->pixels[index * BPP + 1] << 16);
	color |= (t->pixels[index * BPP + 2] << 8);
	color |= (t->pixels[index * BPP + 3]);
	return (color);
}

/**
 * @brief Convert color from RGB to RGBA format
 * 
 * @param color RGB color array
 * @return RGBA color
 */
static u_int32_t cnv_c(unsigned int *color)
{
	return ((color[0] << 24) | (color[1] << 16) | (color[2] << 8) | 0xFF);
}

static mlx_texture_t	*get_texture_direction(t_data *d)
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

static void	render_loop(t_data *d, t_render *r, int x)
{
	int			y;
	uint32_t	color;
	uint32_t	height;
	mlx_texture_t	*tex;

	y = 0;
	while (y < d->win_h)
	{
		if (y >= d->raycast->wall_start && y <= d->raycast->wall_end)
		{
			tex = get_texture_direction(d);
			height = tex->height;
			r->pixel_y = (int)r->pixel_pos & (height - 1);
			r->pixel_pos += r->step;
			color = get_rgba(tex, (height * r->pixel_y + r->pixel_x));
			mlx_put_pixel(d->image, d->win_w - x - 1, y++, color);
		}
		else if (y > d->raycast->wall_end)
			mlx_put_pixel(d->image, d->win_w - x - 1, y++, cnv_c(d->txs->f_clr));
		else if (y < d->raycast->wall_start)
			mlx_put_pixel(d->image, d->win_w - x - 1, y++, cnv_c(d->txs->c_clr));
	}
}

int	render_init(t_data *d, t_render *r, t_raycast *c, int x)
{
	int			tmp;

	if (d->raycast->side_flag == TRUE)
		r->wall_x = d->player->pos_x + c->walldist * c->raydir_x;
	else
		r->wall_x = d->player->pos_y + c->walldist * c->raydir_y;
	r->wall_x -= floor(r->wall_x);
	r->pixel_x = (int)(r->wall_x * d->texture_no->width);
	r->step = 1.0 * d->texture_no->height / c->lineheight;
	tmp = c->wall_start - (d->win_w / 2) + (c->lineheight / 2);
	r->pixel_pos = tmp * r->step;
	render_loop(d, r, x);
	return (0);
}
