/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:32 by mfleury           #+#    #+#             */
/*   Updated: 2025/04/07 15:02:50 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bonus.h"

time_t	get_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error while fetching current time \n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

time_t	get_time_us(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error while fetching current time \n", 2);
	return (time.tv_usec);
}

int	cub_sleep(size_t pause)
{
	time_t			x;

	x = get_time_us() + (time_t)pause;
	while (get_time_us() < x)
	{
		if (get_time_us () >= x)
			break;
	}
	return (0);
}
