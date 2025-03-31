/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:55:43 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/31 19:26:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycast_dist_next_grid(t_raycast *c, t_player *p)
{
	if (c->raydir_x < 0)
	{
		c->step_x = -1;
		c->sidedist_x = (p->pos_x - c->map_x) * c->deltadist_x;
	}
	else
	{
		c->step_x = 1;
		c->sidedist_x = (c->map_x + 1.0 - p->pos_x) * c->deltadist_x;
	}
	if (c->raydir_y < 0)
	{
		c->step_y = -1;
		c->sidedist_y = (p->pos_y - c->map_y) * c->deltadist_y;
	}
	else
	{
		c->step_y = 1;
		c->sidedist_y = (c->map_y + 1.0 - p->pos_y) * c->deltadist_y;
	}
}

static void	raycast_dist_to_wall(t_data *d, t_raycast *c, t_player *p)
{
	c->hit_flag = FALSE;
	while (c->hit_flag == FALSE)
	{
		if (c->sidedist_x < c->sidedist_y)
		{
			c->sidedist_x += c->deltadist_x;
			c->map_x += c->step_x;
			c->side_flag = FALSE;
		}
		else
		{
			c->sidedist_y += c->deltadist_y;
			c->map_y += c->step_y;
			c->side_flag = TRUE;
		}
		if (c->map_x < 0 || c->map_x >= d->map->map_size->x
			|| c->map_y < 0 || c->map_y >= d->map->map_size->y)
			return ;
		if (d->map->i_map[c->map_y][c->map_x] == 1)
			c->hit_flag = TRUE;
	}
	if (c->side_flag == FALSE)
		c->walldist = (c->map_x - p->pos_x + (1 - c->step_x) / 2) / c->raydir_x;
	else
		c->walldist = (c->map_y - p->pos_y + (1 - c->step_y) / 2) / c->raydir_y;
}

static void	raycast_wall_height(t_data *d, t_raycast *c)
{
	c->lineheight = (int)(d->win_h / c->walldist);
	c->wall_start = -c->lineheight / 2 + d->win_h / 2;
	if (c->wall_start < 0)
		c->wall_start = 0;
	c->wall_end = c->lineheight / 2 + d->win_h / 2;
	if (c->wall_end >= d->win_h)
		c->wall_end = d->win_h - 1;
}


int	raycast_loop(t_data *d, t_raycast *c, t_player *p)
{
	int			x;

	x = 0;
	while (x < d->win_w)
	{
		
		c->map_x = (int)p->pos_x;
		c->map_y = (int)p->pos_y;
		p->camera_x = 2 * ((double)x / (double)d->win_w) - 1;
		c->raydir_x = p->dir_x + p->plane_x * p->camera_x;
		c->raydir_y = p->dir_y + p->plane_y * p->camera_x;
		if (c->raydir_x == 0)
			c->deltadist_x = 1e30;
		else
			c->deltadist_x = fabs(1 / c->raydir_x);
		if (c->raydir_y == 0)
			c->deltadist_y = 1e30;
		else
			c->deltadist_y = fabs(1 / c->raydir_y);
		raycast_dist_next_grid(c, p);
		raycast_dist_to_wall(d, c, p);
		raycast_wall_height(d, c);
		render_init(d, d->render, c, x);
		x++;
	}
	return (0);
}

/*int	raycast_init(t_mlx *cub)
{
	int	testmap[10][15] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,5,1,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,0,1,1,1,1,1,0,1,1},
		{1,1,0,0,0,0,0,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
		// floor_ceiling(d, x, c->wall_start, c->wall_end);
		render_init(d, d->render, c, x);
	int	i;
	int	j;

	cub->raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	cub->player = (t_player *)ft_calloc(1, sizeof(t_player));
	cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
	if (cub->raycast == NULL || cub->player == NULL || cub->render == NULL)
		exit(1);
	cub->map = (int **)ft_calloc(10, sizeof(int *));
	if (cub->map == NULL)
		exit(1);
	i = 0;
	while (i < 10)
	{
		cub->map[i] = (int *)ft_calloc(15, sizeof(int));
		if (cub->map[i] == NULL)
			exit(1);
		j = 0;
		while (j < 15)
		{
			cub->map[i][j] = testmap[i][j];
			if (cub->map[i][j] == 5)
			{
				cub->player->pos_x = j;
				cub->player->pos_y = i;
			}
			j++;
		}
		i++;
	}
	cub->player->dir_x = 1;
	cub->player->dir_y = 1;
	cub->player->plane_x = 0.0;
	cub->player->plane_y = 0.5;
	cub->texture = mlx_load_png(TEST_TXT);
	if (cub->texture == NULL)
		exit (1);
	cub->image = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (cub->image == NULL)
		exit (1);
	raycast_loop(cub, cub->raycast, cub->player);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)*/

int	raycast_init(t_data *d)
{
	d->raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	d->player = (t_player *)ft_calloc(1, sizeof(t_player));
	d->render = (t_render *)ft_calloc(1, sizeof(t_render));
	if (!d->raycast || !d->player || !d->render)
		ftl_err("in raycast_init1", d);
	set_player_location_and_dir(d);
	d->texture_no = mlx_load_png(d->txs->no_tx);
	d->texture_so = mlx_load_png(d->txs->so_tx);
	d->texture_we = mlx_load_png(d->txs->we_tx);
	d->texture_ea = mlx_load_png(d->txs->ea_tx);
	if (d->texture_no == NULL || d->texture_so == NULL || d->texture_we == NULL || d->texture_ea == NULL)
		ftl_err("in raycast_init2", d);
	d->image = mlx_new_image(d->mlx, d->win_w, d->win_h);
	if (d->image == NULL)
		ftl_err("in raycast_init3", d);
	raycast_loop(d, d->raycast, d->player);
	if (mlx_image_to_window(d->mlx, d->image, 0, 0) < 0)
		printf("error loading image to window");
	return (0);
}
