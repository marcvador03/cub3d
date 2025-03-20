/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:24 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/20 16:12:03 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_init(t_mlx *cub, t_render *r, t_raycast *c, int x);

static void	raycast_dist_next_grid(t_raycast *c, t_player *p)
{
	if (c->rayDirX == 0)
		c->deltaDistX = 1e30;
	else
		c->deltaDistX = fabs(1 / c->rayDirX);	
	if (c->rayDirY == 0)
		c->deltaDistY = 1e30;
	else
		c->deltaDistY = fabs(1 / c->rayDirY);
	if (c->rayDirX < 0)
	{
		c->stepX = -1;
		c->sideDistX = (p->posX - c->mapX) * c->deltaDistX;
	}
	else
	{
		c->stepX = 1;
		c->sideDistX = (c->mapX + 1.0 - p->posX) * c->deltaDistX;
	}
	if (c->rayDirY < 0)
	{	
		c->stepY = -1;
		c->sideDistY = (p->posY - c->mapY) * c->deltaDistY;
	}
	else
	{
		c->stepY = 1;
		c->sideDistY = (c->mapY + 1.0 - p->posY) * c->deltaDistY;
	}
}

static void	raycast_dist_to_wall(t_mlx *cub, t_raycast *c, t_player *p)
{
	c->hit_flag = FALSE;
	while (c->hit_flag == FALSE)
	{
		if (c->sideDistX < c->sideDistY)
		{
			c->sideDistX += c->deltaDistX;
			c->mapX += c->stepX;
			c->side_flag = FALSE;
		}
		else
		{
			c->sideDistY += c->deltaDistY;
			c->mapY += c->stepY;
			c->side_flag = TRUE;
		}
		if (cub->map[c->mapY][c->mapX] == '1')
			c->hit_flag = TRUE;
	}
	if (c->side_flag == FALSE)
		c->walldist = (c->mapX - p->posX + (0 - c->stepX) / 2) / c->rayDirX;
	else
		c->walldist = (c->mapY - p->posY + (1 - c->stepY) / 2) / c->rayDirY;
}

static void	raycast_wall_height(t_mlx *cub, t_raycast *c)
{
	c->lineHeight = (int)(cub->win_h / c->walldist);
	c->wall_start = -c->lineHeight / 2 + cub->win_h / 2;
	if (c->wall_start < 0)
		c->wall_start = 0;
	c->wall_end = c->lineHeight / 2 + cub->win_h / 2;
	if (c->wall_end < 0)
		c->wall_end = 0;
}

int	raycast_loop(t_mlx *cub, t_raycast *c, t_player *p)
{
	int			x;

	x = 0;
	while (x < cub->win_w)
	{
		c->mapX = (int)p->posX;
		c->mapY = (int)p->posY;
		p->cameraX = 2 * ((double)x / (double)cub->win_w) - 1;
		c->rayDirX = p->dirX + p->planeX * p->cameraX;
		c->rayDirY = p->dirY + p->planeY * p->cameraX;
		raycast_dist_next_grid(c, p);
		raycast_dist_to_wall(cub, c, p);
		raycast_wall_height(cub, c);
		render_init(cub, cub->render, c, x);
		x++;
	}
	return (0);
}

int	raycast_init(t_data *d)
{
	
	d->cub->raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	d->cub->player = (t_player *)ft_calloc(1, sizeof(t_player));
	d->cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
	if (!d->cub->raycast || !d->cub->player	|| !d->cub->render)
		ftl_err("in raycast_init1", d);
	d->cub->map = d->map->arr;
	set_player_location_and_dir(d);
	d->cub->texture = mlx_load_png(TEST_TXT);
	if (d->cub->texture == NULL)
		ftl_err("in raycast_init2", d);
	d->cub->image = mlx_new_image(d->cub->mlx, d->cub->win_w, d->cub->win_h);
	if (d->cub->image == NULL)
		ftl_err("in raycast_init3", d);
	raycast_loop(d->cub, d->cub->raycast, d->cub->player);
	if (mlx_image_to_window(d->cub->mlx, d->cub->image, 0, 0) < 0)
		printf("error loading image to window");
	return (0);
}
