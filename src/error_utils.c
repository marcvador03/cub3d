/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:15:39 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/11 14:44:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/** 
 * @brief This function will print an error message and exit the program
 * 
*/
void	ftl_err(const char *msg, t_data *data)
{
	printf("Error\n %s\n", msg);
	free_data(data);
	//close all the files
	//close all the windows
	//exit the program
	exit (1);
}
