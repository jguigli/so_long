/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:20:20 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/14 16:20:21 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	*ft_str_printf(const char *format, ...)
{
	char	*str;
	va_list	arg;
	int		countplus;

	countplus = 0;
	va_start(arg, format);
	if (!format)
		return (NULL);
	str = read_format(format, arg, &countplus);
	va_end(arg);
	return (str);
}

int	check_y_possibility(t_data *game, char pos, int dir)
{
	char	*str;

	str = NULL;
	if (pos == 'y' && game->map[game->pos_y + 1 * dir][game->pos_x] != '1'
	&& (game->map[game->pos_y + 1 * dir][game->pos_x] != 'E'
	|| game->collectible_count == game->check_map.collectible))
	{
		game->count_move++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.mlx_img, (4 * IMG_W), (0 * IMG_H));
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.mlx_img, (5 * IMG_W), (0 * IMG_H));
		str = ft_str_printf("Number of move done : %d", game->count_move);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 16, 16, WHITE_PIXEL, str);
		mlx_do_sync(game->mlx_ptr);
		free(str);
		return (1);
	}
	return (0);
}

int	check_x_possibility(t_data *game, char pos, int dir)
{
	char	*str;

	str = NULL;
	if (pos == 'x' && game->map[game->pos_y][game->pos_x + 1 * dir] != '1'
	&& (game->map[game->pos_y][game->pos_x + 1 * dir] != 'E'
	|| game->collectible_count == game->check_map.collectible))
	{
		game->count_move++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.mlx_img, (4 * IMG_W), (0 * IMG_H));
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.mlx_img, (5 * IMG_W), (0 * IMG_H));
		str = ft_str_printf("Number of move done : %d", game->count_move);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 16, 16, WHITE_PIXEL, str);
		mlx_do_sync(game->mlx_ptr);
		free(str);
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
