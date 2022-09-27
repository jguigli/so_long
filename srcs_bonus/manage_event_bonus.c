/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:20:48 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:20:49 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	handle_cross(t_data *game)
{
	mlx_loop_end(game->mlx_ptr);
	close_game(game);
	return (0);
}

void	get_collectible(t_data *game)
{
	game->collectible_count++;
	game->map[game->pos_y][game->pos_x] = '0';
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->floor.mlx_img, (game->pos_x * IMG_W), (game->pos_y * IMG_H));
	if (game->collectible_count != game->check_map.collectible)
		ft_printf("Chest(s) collected, remains %d\n",
			game->check_map.collectible - game->collectible_count);
	else
		ft_printf("You have collected all the chest(s), go to the scroll\n");
}

int	event_key(int keysym, t_data *game)
{
	if (keysym)
	{
		if (keysym == XK_w)
			check_move_character(game, 'y', UP);
		else if (keysym == XK_s)
			check_move_character(game, 'y', DOWN);
		else if (keysym == XK_a)
			check_move_character(game, 'x', LEFT);
		else if (keysym == XK_d)
			check_move_character(game, 'x', RIGHT);
		else if (keysym == XK_Escape)
			close_game(game);
	}
	return (0);
}

void	check_move_character(t_data *game, char pos, int dir)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->floor.mlx_img, (game->pos_x * IMG_W), (game->pos_y * IMG_H));
	if (check_y_possibility(game, pos, dir))
		game->pos_y += (1 * dir);
	else if (check_x_possibility(game, pos, dir))
		game->pos_x += (1 * dir);
	else if (check_y_exit(game, pos, dir) || check_x_exit(game, pos, dir))
		ft_printf("Not enough collectible to exit\n");
	if (game->map[game->pos_y][game->pos_x] == 'C')
		get_collectible(game);
	move_player(game, pos, dir);
	if (game->map[game->pos_y][game->pos_x] == 'A')
		touch_enemy(game);
	if (game->map[game->pos_y][game->pos_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.mlx_img, (game->pos_x * IMG_W), (game->pos_y * IMG_H));
		ft_printf("You finished the game\n(Press ESC or click on the cross)\n");
		mlx_key_hook(game->win_ptr, &after_event, game);
	}
}

void	move_player(t_data *game, char pos, int dir)
{
	if (pos == 'y' && dir == UP)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->character_back.mlx_img, (game->pos_x * IMG_W),
			(game->pos_y * IMG_H));
	}
	if (pos == 'y' && dir == DOWN)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->character_front.mlx_img, (game->pos_x * IMG_W),
			(game->pos_y * IMG_H));
	}
	if (pos == 'x' && dir == LEFT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->character_left.mlx_img, (game->pos_x * IMG_W),
			(game->pos_y * IMG_H));
	}
	if (pos == 'x' && dir == RIGHT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->character_right.mlx_img, (game->pos_x * IMG_W),
			(game->pos_y * IMG_H));
	}
	mlx_do_sync(game->mlx_ptr);
}
