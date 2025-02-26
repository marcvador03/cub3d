/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:24 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/26 19:20:23 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_mlx *cub)
{
	//mlx_texture_t*	texture;
	mlx_image_t*	image;
	t_raycast	r;
	int			x;
	/*int	testmap[10][15] = 
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
	};*/

	r.posX = 2;
	r.posY = 1;
	r.dirX = -1;
	r.dirY = 0;
	r.planeX = 0;
	r.planeY = 0.66;
	x = 0;
	while (x < 1080)
	{
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
