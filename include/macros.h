/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:57:57 by mpietrza          #+#    #+#             */
/*   Updated: 2025/04/03 12:57:19 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//boolean values for int
# define TRUE	1
# define FALSE	0

//macros for moves
# define RESET	0
# define FWD	1
# define BK		2
# define LEFT	3
# define RIGHT	4
# define TURN_L	1
# define TURN_R	-1
# define MV_SPD_FCTR	20
# define RT_ANGLE_FCTR	40

//colors
# define RST	"\033[0m"
# define BLK	"\033[30m"
# define RED	"\033[31m"  
# define GRN	"\033[32m"
# define YLW	"\033[33m"
# define BLU	"\033[34m"
# define MGN	"\033[35m"
# define CYN	"\033[36m"
# define WHT	"\033[37m"
# define BLD	"\033[1m" 

//bits per pixel
# define BPP 4

#endif
