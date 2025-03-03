/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milosz <milosz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:15:39 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/03 22:57:29 by milosz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/** 
 * @brief This function will print an error message and exit the program
 * 
*/
void	ftl_err(char msg[1024])
{
	printf("Error\n %s\n", msg);
	exit (1);
}
