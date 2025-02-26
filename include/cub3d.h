/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:58 by mfleury           #+#    #+#             */
/*   Updated: 2025/02/26 11:24:27 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <limits.h>

# include "../libft/libft.h"
# include "../mlx42/include/MLX42/MLX42.h"

typedef struct s_mlx
{
	mlx_t	*mlx;
	char	*map_path;
}	t_mlx;

void	free_s(void *ptr);
void	free_d(char **ptr);

#endif
