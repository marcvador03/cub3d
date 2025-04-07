/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:32:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/07 18:22:22 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

static void	check_args(int argc, char **argv, t_data *d)
{
	if (argc != 2)
		ftl_err("in arguments", d);
	else
	{
		d->map_path = ft_strdup(argv[1]);
		if (!d->map_path)
			ftl_err("in malloc", d);
	}
	return ;
}

static t_mouse *mouse_struct_init(t_data *d)
{
	t_mouse	*m;
		
	m = (t_mouse *)safe_malloc(sizeof(t_mouse), NULL);
	m->x = d->win_w / 2;
	m->y = d->win_h / 2;
	m->d = d;
	mlx_set_mouse_pos(d->mlx, m->x, m->y);
	return (m);
}

int	main(int argc, char **argv)
{
	t_data	*d;
	t_mouse	*m;

	d = (t_data *)safe_malloc(sizeof(t_data), NULL);
	structs_init(d);
	check_args(argc, argv, d);
	parsing_process(d);
	d->win_w = 1280;
	d->win_h = 580;
	d->aspect_ratio = (double)d->win_w / (double)d->win_h;
	d->mlx = mlx_init(d->win_w, d->win_h, "CUB3D", true);
	if (!d->mlx)
		ftl_err("mlx_init() failed", d);
	m = mouse_struct_init(d);
	mlx_cursor_hook(d->mlx, mouse_move, m);
	mlx_key_hook(d->mlx, key_handler, d);
	mlx_loop_hook(d->mlx, &move_player, d);
	mlx_close_hook(d->mlx, hook_close, d);
	raycast_init(d);
	mlx_loop(d->mlx);
	exit_normal(d);
}
