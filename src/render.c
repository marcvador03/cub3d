/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:24 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/27 10:45:53 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_mlx *cub)
{
	//mlx_texture_t*	texture;
	mlx_image_t*	image;
	t_raycast	r;
	int			x;
	int	testmap[10][15] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,0,0,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,0,0,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,0,0,0,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	r.posX = 2;
	r.posY = 1;
	r.dirX = -1;
	r.dirY = 0;
	r.planeX = 0;
	r.planeY = 0.66;
	x = 0;
	while (x < 1080)
	{
		r.mapX = r.posX;
		r.mapY = r.posY;
		r.cameraX = 2 * (double)x / 1080 - 1;
		r.rayDirX = r.dirX + r.planeX * r.cameraX;
		r.rayDirY = r.dirY + r.planeY * r.cameraX;
		if (r.rayDirX == 0)
			r.deltaDistX = 1e30;
		else
			r.deltaDistX = fabs(1 / r.rayDirX);	
		if (r.rayDirY == 0)
			r.deltaDistY = 1e30;
		else
			r.deltaDistY = fabs(1 / r.rayDirY);
		if (r.rayDirX < 0)
		{
			r.stepX = -1;
			r.sideDistX = (r.posX - r.mapX) * r.deltaDistX;
		}
		if (r.rayDirX > 0)
		{
			r.stepX = 1;
			r.sideDistX = (r.mapX + 1 - r.posX) * r.deltaDistX;
		}
		if (r.rayDirY < 0)
		{
			r.stepY = -1;
			r.sideDistY = (r.posY - r.mapY) * r.deltaDistY;
		}
		if (r.rayDirY > 0)
		{
			r.stepY = 1;
			r.sideDistY = (r.mapY + 1 - r.posY) * r.deltaDistY;
		}
		r.hit_flag = FALSE;
		while (r.hit_flag == FALSE)
		{
			if (r.sideDistX < r.sideDistY)
			{
				r.sideDistX += r.deltaDistX;
				r.mapX += r.stepX;
				r.side_flag = FALSE;
			}
			else
			{
				r.sideDistY += r.deltaDistY;
				r.mapY += r.stepY;
				r.side_flag = TRUE;
			}
			if (testmap[r.mapX][r.mapY] == 1)
				r.hit_flag = TRUE;
		}
		if (r.side_flag == FALSE)
			r.perpWallDist = (r.sideDistX - r.deltaDistX);
		else
			r.perpWallDist = (r.sideDistY - r.deltaDistY);
		r.lineHeight = 24 / (int)r.perpWallDist;
		x++;
	}	
	image = mlx_new_image(cub->mlx, 204, 204);
	ft_memset(image->pixels, 0xFFFFFF, image->width * image->height * 4);
	//mlx_resize_image(image, 204, 204);
	if (mlx_image_to_window(cub->mlx, image, 0, 0) < 0)
		printf("error loading image to window");
	/*while (1)
	{

	}*/
	return (0);
}

	/*texture = mlx_load_png(TEST_TXT);
	if (texture == 0)
		printf("error loading texture");
	//texture->width = 204;
	//texture->height = 204;
	image = mlx_texture_to_image(cub->mlx, texture);
	if (image == 0)
		printf("error loading image");*/
