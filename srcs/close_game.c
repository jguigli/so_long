/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:17:52 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:17:54 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_struct(t_data *game)
{
	int	x;

	x = 0;
	while (x < game->size_y)
		free(game->map[x++]);
	free(game->map);
	free(game->mlx_ptr);
	free(game);
}

void	close_game(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->floor.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->exit.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->character_front.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->character_back.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->character_right.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->character_left.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->collectible.mlx_img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	close_struct(game);
	exit(EXIT_SUCCESS);
}
