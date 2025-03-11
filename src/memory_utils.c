/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:34:38 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/11 12:55:01 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will allocate memory and check if the allocation 
 * was successful
 * 
 * @param size
 * @return void* 
 */
void	*safe_malloc(size_t size, t_data *data)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_data(data);
		ftl_err("in memory allocation", data);
	}
	return (ptr);
}


