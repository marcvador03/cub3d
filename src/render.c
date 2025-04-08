/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:57:54 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/08 11:10:02 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will inject the texture into the image
 * 
 * @param d t_data* - the data structure
 * @param t mlx_texture_t* - the texture
 * @param t_index int - the index of the texture
 * @param i_index int - the index of the image
 * @return void
 */
static void	inject_img(t_data *d, mlx_texture_t *t, int t_index, int i_index)
{
	if (t_index < 0 || t_index >= (int)(t->width * t->height * BPP))
		return;
	if (i_index < 0 || (int32_t)i_index >= (int)(d->win_w * d->win_h * BPP))
		return;
	d->image->pixels[i_index] = t->pixels[t_index];
	d->image->pixels[i_index + 1] = t->pixels[t_index + 1];
	d->image->pixels[i_index + 2] = t->pixels[t_index + 2];
	d->image->pixels[i_index + 3] = t->pixels[t_index + 3];
	return ;
}

/**
 * @brief This function will inject the color into the image
 * 
 * @param d t_data* - the data structure
 * @param color unsigned int[3] - the color
 * @param i_index int - the index of the image
 * @return void
 */
static void	inject_col_img(t_data *d, unsigned int color[3], int i_index)
{
	d->image->pixels[i_index] = color[0];
	d->image->pixels[i_index + 1] = color[1];
	d->image->pixels[i_index + 2] = color[2];
	d->image->pixels[i_index + 3] = 0xFF;
	return ;
}

/**
 * @brief This function will get the texture based on the direction
 * 
 * @param d t_data* - the data structure
 * @return mlx_texture_t* - the texture
 */
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

/**
 * @brief This function will render the loop
 * 
 * @param d t_data* - the data structure
 * @param r t_render* - the render structure
 * @param x int - the x coordinate
 * @return void
 */
static void	render_loop(t_data *d, t_render *r, int x)
{
	int				y;
	uint32_t		height;
	int				index;
	mlx_texture_t	*t;

	y = 0;
	//time_stamp("render loop", 0, d);
	while (y < d->win_h)
	{
		if (y >= d->raycast->wall_start && y <= d->raycast->wall_end)
		{
			t = get_texture_direction(d);
			height = t->height;
			r->pixel_y = (int)r->pixel_pos & (height - 1);
			r->pixel_pos += r->step;
			index = height * r->pixel_y + r->pixel_x;
			inject_img(d, t, index * BPP, ((y++) * d->win_w + x) * BPP);
		}
		else if (y > d->raycast->wall_end)
			inject_col_img(d, d->txs->f_clr, ((y++) * d->win_w + x) * BPP);
		else if (y < d->raycast->wall_start)
			inject_col_img(d, d->txs->c_clr, ((y++) * d->win_w + x) * BPP);
	}
	//time_stamp("render loop", 1, d);
}

/**
 * @brief This function will initialize the render
 * 
 * @param d t_data* - the data structure
 * @param r t_render* - the render structure
 * @param c t_raycast* - the raycast structure
 * @param x int - the x coordinate
 * @return int - 0 if success
 */
int	render_init(t_data *d, t_render *r, t_raycast *c, int x)
{
	int			tmp;
	
	//time_stamp("render init", 0, d);
	if (d->raycast->side_flag == TRUE)
		r->wall_x = d->player->pos_x + c->walldist * c->raydir_x;
	else
		r->wall_x = d->player->pos_y + c->walldist * c->raydir_y;
	r->wall_x -= floor(r->wall_x);
	r->wall_x *= d->aspect_ratio;
	r->pixel_x = (int)(r->wall_x * d->texture_no->width);
	r->step = 1.0 * d->texture_no->height / c->lineheight;
	tmp = c->wall_start - (d->win_h / 2) + (c->lineheight / 2);
	r->pixel_pos = tmp * r->step;
	//time_stamp("render init", 1, d);
	render_loop(d, r, x);
	return (0);
}
