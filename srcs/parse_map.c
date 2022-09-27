/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:44 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:18:45 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_string_map(char *mapname)
{
	char	*line;
	char	*str;
	int		fd;

	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (line)
	{
		str = ft_strjoin(str, line);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (str);
}

char	**parse_map(char *mapname)
{
	char	**map;
	char	*str;

	str = get_string_map(mapname);
	map = ft_split(str, '\n');
	free (str);
	return (map);
}
