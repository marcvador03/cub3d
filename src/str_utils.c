/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:09:15 by mpietrza          #+#    #+#             */
/*   Updated: 2025/03/10 18:54:10 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_arr_print(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

char	*ft_safe_strdup_w_o_leading_spaces(char *line, t_data *data)
{
	int 	i;
	char	*pure_line;

	i = 0;
	printf("line: %s\n", line);
	while (line[i] == ' ')
		i++;
	pure_line = ft_strdup(&line[i]);
	if (!pure_line)
		ftl_err("in deleting empty space", data);
	return (pure_line);
}
