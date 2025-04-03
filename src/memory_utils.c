/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:34:38 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/03 15:36:33 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will allocate memory and check if the allocation 
 * was successful
 * 
 * @param size size_t - size of the memory to allocate
 * @param d t_data* - pointer to the data structure
 * @return void* 
 */
void	*safe_malloc(size_t size, t_data *d)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_data(d);
		ftl_err("in memory allocation", d);
	}
	return (ptr);
}
