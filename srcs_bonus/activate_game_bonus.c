/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activate_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:19:22 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:19:24 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	load_xpm(t_data *game)
{
	game->character_front.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/character_front.xpm", &game->character_front.width,
			&game->character_front.height);
	if (!game->character_front.mlx_img)
		close_game(game);
	game->wall.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/tileset/wall.xpm", &game->wall.width, &game->wall.height);
	if (!game->wall.mlx_img)
		close_game(game);
	game->floor.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/tileset/floor.xpm", &game->floor.width,
			&game->floor.height);
	if (!game->floor.mlx_img)
		close_game(game);
	game->collectible.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/chest.xpm", &game->collectible.width,
			&game->collectible.height);
	if (!game->collectible.mlx_img)
		close_game(game);
}

void	load_xpm2(t_data *game)
{
	game->exit.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/scroll_exit.xpm", &game->exit.width,
			&game->exit.height);
	if (!game->exit.mlx_img)
		close_game(game);
	game->character_back.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/character_back.xpm", &game->character_back.width,
			&game->character_back.height);
	if (!game->character_back.mlx_img)
		close_game(game);
	game->character_right.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/character_right.xpm", &game->character_right.width,
			&game->character_right.height);
	if (!game->character_right.mlx_img)
		close_game(game);
	game->character_left.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/character_left.xpm", &game->character_left.width,
			&game->character_left.height);
	if (!game->character_left.mlx_img)
		close_game(game);
}

void	put_image(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, (y * IMG_H), (x * IMG_W));
}

void	get_the_right_image(char c, t_data *game, int i, int j)
{	
	if (c == '1')
		put_image(game, game->wall.mlx_img, i, j);
	if (c == '0')
		put_image(game, game->floor.mlx_img, i, j);
	if (c == 'E')
		put_image(game, game->exit.mlx_img, i, j);
	if (c == 'C')
		put_image(game, game->collectible.mlx_img, i, j);
	if (c == 'P')
	{
		put_image(game, game->character_front.mlx_img, i, j);
		game->pos_x = j;
		game->pos_y = i;
	}
	if (c == 'A')
		put_image(game, game->enemy.mlx_img, i, j);
}

void	launch_game(t_data *game)
{
	int		i;
	int		j;

	i = 0;
	load_xpm(game);
	load_xpm2(game);
	load_xpm3(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			get_the_right_image(game->map[i][j], game, i, j);
			j++;
		}
		i++;
	}
}
