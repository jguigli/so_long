/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:20 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:18:21 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	after_event(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}

int	check_y_possibility(t_data *game, char pos, int dir)
{
	if (pos == 'y' && game->map[game->pos_y + 1 * dir][game->pos_x] != '1'
	&& (game->map[game->pos_y + 1 * dir][game->pos_x] != 'E'
	|| game->collectible_count == game->check_map.collectible))
	{
		game->count_move++;
		ft_printf("Number of move done : %d\n", game->count_move);
		return (1);
	}
	return (0);
}

int	check_x_possibility(t_data *game, char pos, int dir)
{
	if (pos == 'x' && game->map[game->pos_y][game->pos_x + 1 * dir] != '1'
	&& (game->map[game->pos_y][game->pos_x + 1 * dir] != 'E'
	|| game->collectible_count == game->check_map.collectible))
	{
		game->count_move++;
		ft_printf("Number of move done : %d\n", game->count_move);
		return (1);
	}
	return (0);
}

int	check_y_exit(t_data *game, char pos, int dir)
{
	if (pos == 'y' && game->map[game->pos_y + 1 * dir][game->pos_x] != '1'
	&& (game->map[game->pos_y + 1 * dir][game->pos_x] == 'E'
	|| game->collectible_count != game->check_map.collectible))
		return (1);
	return (0);
}

int	check_x_exit(t_data *game, char pos, int dir)
{
	if (pos == 'x' && game->map[game->pos_y][game->pos_x + 1 * dir] != '1'
	&& (game->map[game->pos_y][game->pos_x + 1 * dir] == 'E'
	|| game->collectible_count != game->check_map.collectible))
		return (1);
	return (0);
}
