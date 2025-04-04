/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:02:36 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/04 18:35:13 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BONUS_H
# define BONUS_H

# include "cub3d.h"
# define MOUSE_ANGLE_FCTR 1 

typedef struct s_mouse
{
	int32_t	x;
	int32_t	y;
	t_data	*d;

}	t_mouse;

void	mouse_move(double xpos, double ypos, void *param);

#endif
