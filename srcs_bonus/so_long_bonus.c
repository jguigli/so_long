/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:21:07 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:21:09 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*game;

	game = malloc(sizeof(t_data));
	if (!game)
		return (-1);
	initialisation_struct_game(game, argv[1]);
	if (check_error(argc, argv, game))
	{
		close_struct(game);
		return (-1);
	}
	create_window(game);
	ft_printf("Collect all the chests and escape with the scroll\n");
	launch_game(game);
	mlx_hook(game->win_ptr, DestroyNotify,
		StructureNotifyMask, handle_cross, game);
	mlx_key_hook(game->win_ptr, event_key, game);
	mlx_loop(game->mlx_ptr);
	free(game);
	return (0);
}
