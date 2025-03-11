/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:09:15 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/11 14:58:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function will duplicate a string without the newline character
 * 
 * @param str char*
 * @param data t_data*
 * @return char* 
 */
char	*ft_strdup_w_o_nl(char *str, t_data *data)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	while (str[i] && str[i] != '\n')
	{
		len++;
		i++;
	}
	new_str = (char *)safe_malloc((sizeof(char) * (len + 1)), data);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * @brief This function will print an array of strings
 * 
 * @param arr char**
 * @return void
 */
void	ft_arr_print(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

/**
 * @brief This function will duplicate a string without preceding spaces
 * 
 * @param line char*
 * @param data t_data*
 * @return char*
 */
char	*ft_safe_strdup_w_o_preceding_spaces(char *line, t_data *data)
{
	int		i;
	char	*pure_line;

	i = 0;
	while (line[i] == ' ')
		i++;
	pure_line = ft_strdup(&line[i]);
	if (!pure_line)
		ftl_err("in deleting empty space", data);
	return (pure_line);
}
