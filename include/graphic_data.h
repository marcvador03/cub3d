/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:42:13 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/28 11:55:41 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_DATA_H
# define GRAPHIC_DATA_H

typedef struct s_txtr_data
{
	char			*no_txtr;
	char			*so_txtr;
	char			*we_txtr;
	char			*ea_txtr;
	unsigned int	f_clr[3];
	unsigned int	c_clr[3];
}	t_txtr_data;

#endif
