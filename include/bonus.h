/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:02:36 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/08 15:06:30 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BONUS_H
# define BONUS_H

# include "cub3d.h"
# include "sys/time.h"
# define MOUSE_THROTTLE 5
# define MOUSE_STEP 0

typedef struct s_mouse
{
	int32_t		x;
	int32_t		y;
	long int	start_t;
	int32_t		cnt;
	t_data	*d;

}	t_mouse;

void	mouse_move(double xpos, double ypos, void *param);

#endif
