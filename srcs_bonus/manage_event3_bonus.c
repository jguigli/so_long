/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:20:39 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:20:40 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	after_event(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}

void	touch_enemy(t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->enemy.mlx_img, (game->pos_x * IMG_W), (game->pos_y * IMG_H));
	ft_printf("GAME OVER\n(Press ESC or click on the cross)\n");
	mlx_key_hook(game->win_ptr, &after_event, game);
}

void	load_xpm3(t_data *game)
{
	game->enemy.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/sprites/enemy.xpm", &game->enemy.width,
			&game->enemy.height);
	if (!game->enemy.mlx_img)
		close_game(game);
}
