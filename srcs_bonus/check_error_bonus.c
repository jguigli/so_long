/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:19:37 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:19:38 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_error_map2(t_data *game)
{
	while (game->check_map.line != NULL)
	{
		if (check_different_length(game))
			return (1);
		if (game->check_map.count_line == 0)
		{
			if (check_first_row(game))
				return (1);
		}
		else if (game->check_map.count_line > 0
			&& game->check_map.count_line < game->check_map.line_max)
		{
			if (check_mid_row(game))
				return (1);
		}
		else if (game->check_map.count_line == game->check_map.line_max)
		{
			if (check_last_row(game))
				return (1);
		}
		free(game->check_map.line);
		game->check_map.line = get_next_line(game->check_map.fd);
		game->check_map.count_line++;
	}
	return (0);
}

int	check_error_map(t_data *game)
{
	if (check_error_map2(game))
	{
		while (game->check_map.line)
		{
			free(game->check_map.line);
			game->check_map.line = get_next_line(game->check_map.fd);
		}
		close(game->check_map.fd);
		return (1);
	}
	free(game->check_map.line);
	close(game->check_map.fd);
	if (check_item_map(game))
		return (1);
	return (0);
}

int	check_error_arg(int argc)
{
	if (argc != 2)
		return (1);
	return (0);
}

int	check_file_name(char *mapname)
{
	char	*rep;
	int		fd;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	rep = ft_strrchr(mapname, '.');
	if (rep == NULL || ft_strcmp(rep, ".ber") != 0)
		return (1);
	return (0);
}

int	check_error(int argc, char **argv, t_data *game)
{
	char	*mapname;

	mapname = argv[1];
	if (check_error_arg(argc))
	{
		ft_printf("Error\nThe programm expects one and only argument\n");
		return (1);
	}
	if (check_file_name(mapname) || game->check_map.fd < 0)
	{
		ft_printf("Error\nIncorrect file name\n");
		return (1);
	}
	if (check_error_map(game))
	{
		ft_printf("Error\nThe map is incorrect or empty\n");
		return (1);
	}
	return (0);
}
