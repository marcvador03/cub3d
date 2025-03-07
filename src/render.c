/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:24 by mfleury           #+#    #+#             */
/*   Updated: 2025/03/07 20:24:24 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_mlx *cub, t_render *r)
{
	int			x;
	int			y;

	x = 0;
	while (x < cub->win_w)
	{
		r->mapX = (int)r->posX;
		r->mapY = (int)r->posY;
		r->cameraX = 2 * ((double)x / (double)cub->win_w) - 1;
		r->rayDirX = r->dirX + r->planeX * r->cameraX;
		r->rayDirY = r->dirY + r->planeY * r->cameraX;
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
			r->sideDistX = (r->posX - r->mapX) * r->deltaDistX;
		}
		if (r->rayDirX >= 0)
		{
			r->stepX = 1;
			r->sideDistX = (r->mapX + 1.0 - r->posX) * r->deltaDistX;
		}
		if (r->rayDirY < 0)
		{	
			r->stepY = -1;
			r->sideDistY = (r->posY - r->mapY) * r->deltaDistY;
		}
		if (r->rayDirY >= 0)
		{
			r->stepY = 1;
			r->sideDistY = (r->mapY + 1.0 - r->posY) * r->deltaDistY;
		}
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
			r->walldist = (r->mapX - r->posX + (0 - r->stepX) / 2) / r->rayDirX;
		else
			r->walldist = (r->mapY - r->posY + (1 - r->stepY) / 2) / r->rayDirY;
		r->lineHeight = (int)(cub->win_h / r->walldist);
		r->wall_start = -r->lineHeight / 2 + cub->win_h / 2;
		if (r->wall_start < 0)
			r->wall_start = 0;
		r->wall_end = r->lineHeight / 2 + cub->win_h / 2;
		if (r->wall_end < 0)
			r->wall_end = 0;
		y = r->wall_start;
		while (y < r->wall_end)
			mlx_put_pixel(cub->image, x, y++, 0xFFFFFF);
		x++;
	}
	return (0);
}

int	render_init(t_mlx *cub)
{
	//mlx_texture_t*	texture;
	int	testmap[10][15] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,5,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1,1,1,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int	i;
	int	j;

	cub->render = (t_render *)ft_calloc(1, sizeof(t_render));
	if (cub->render == NULL)
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
				cub->render->posX = j;
				cub->render->posY = i;
			}
			j++;
		}
		i++;
	}
	cub->render->dirX = -1;
	cub->render->dirY = 0;
	cub->render->planeX = 0;
	cub->render->planeY = 0.66;
	cub->image = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (cub->image == NULL)
		exit (1);
	render_loop(cub, cub->render);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		printf("error loading image to window");
	return (0);
}
