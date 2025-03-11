/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:24 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/11 14:30:33 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycast_dist_next_grid(t_render *r, t_player *p)
{
	if (r->rayDirX == 0)
		r->deltaDistX = 1e30;
	else
		r->deltaDistX = fabs(1 / r->rayDirX);	
	if (r->rayDirY == 0)
		r->deltaDistY = 1e30;
	else
		r->deltaDistY = fabs(1 / r->rayDirY);
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (p->posX - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = (r->mapX + 1.0 - p->posX) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{	
		r->stepY = -1;
		r->sideDistY = (p->posY - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = (r->mapY + 1.0 - p->posY) * r->deltaDistY;
	}
}

static void	raycast_dist_to_wall(t_mlx *cub, t_render *r, t_player *p)
{
	r->hit_flag = FALSE;
	while (r->hit_flag == FALSE)
	{
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			r->mapX += r->stepX;
			r->side_flag = FALSE;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			r->mapY += r->stepY;
			r->side_flag = TRUE;
		}
		if (cub->map[r->mapY][r->mapX] == 1)
			r->hit_flag = TRUE;
	}
	if (r->side_flag == FALSE)
		r->walldist = (r->mapX - p->posX + (0 - r->stepX) / 2) / r->rayDirX;
	else
		r->walldist = (r->mapY - p->posY + (1 - r->stepY) / 2) / r->rayDirY;
}

static void	raycast_wall_height(t_mlx *cub, t_render *r)
{
	r->lineHeight = (int)(cub->win_h / r->walldist);
	r->wall_start = -r->lineHeight / 2 + cub->win_h / 2;
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = r->lineHeight / 2 + cub->win_h / 2;
	if (r->wall_end < 0)
		r->wall_end = 0;
}

int	raycast_loop(t_mlx *cub, t_render *r, t_player *p)
{
	int			x;
	int			y;

	x = 0;
	while (x < cub->win_w)
	{
		r->mapX = (int)p->posX;
		r->mapY = (int)p->posY;
		p->cameraX = 2 * ((double)x / (double)cub->win_w) - 1;
		r->rayDirX = p->dirX + p->planeX * p->cameraX;
		r->rayDirY = p->dirY + p->planeY * p->cameraX;
		raycast_dist_next_grid(r, p);
		raycast_dist_to_wall(cub, r, p);
		raycast_wall_height(cub, r);
		y = 0;
		while (y < cub->win_h)
		{
			if (y > r->wall_start && y < r->wall_end)
				mlx_put_pixel(cub->image, cub->win_w - x, y++, 0xFFFFFF);
			else
				mlx_put_pixel(cub->image, cub->win_w - x, y++, 0x00000000);
		}
		x++;
	}
	return (0);
}

int	raycast_init(t_mlx *cub)
{
	//mlx_texture_t*	texture;
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
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int	i;
	int	j;

	cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
	cub->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (cub->render == NULL || cub->player == NULL)
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
				cub->player->posX = j;
				cub->player->posY = i;
			}
			j++;
		}
		i++;
	}
	cub->player->dirX = -1;
	cub->player->dirY = 0;
	cub->player->planeX = 0.0;
	cub->player->planeY = 0.5;
	cub->image = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (cub->image == NULL)
		exit (1);
	raycast_loop(cub, cub->render, cub->player);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		printf("error loading image to window");
	return (0);
}
