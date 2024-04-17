/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:44:37 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:45:27 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_zombie_right(t_data *data)
{
	if (data->timer == 4 * ZOMBIE || (data->timer >= 0 && data->timer < ZOMBIE))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[0].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->timer >= ZOMBIE && data->timer < 2 * ZOMBIE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[1].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->timer >= 2 * ZOMBIE && data->timer < 3 * ZOMBIE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[2].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->timer >= 3 * ZOMBIE && data->timer < 4 * ZOMBIE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[3].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[0].width;
}

void	put_zombie_left(t_data *data)
{
	if (data->timer == 4 * ZOMBIE || (data->timer >= 0 && data->timer < ZOMBIE))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[4].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->timer >= ZOMBIE && data->timer < 2 * ZOMBIE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[5].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->timer >= 2 * ZOMBIE && data->timer < 3 * ZOMBIE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[6].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->timer >= 3 * ZOMBIE && data->timer < 4 * ZOMBIE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->zombie[7].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[0].width;
}

void	put_player_death(t_data *data)
{
	if (data->player_dead < PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[8].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->player_dead >= PLAYER && data->player_dead < PLAYER * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[9].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->player_dead >= PLAYER * 2 && data->player_dead < PLAYER * 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[10].ptr, data->x_to_fill, data->y_to_fill);
	else if (data->player_dead >= PLAYER * 3 && data->player_dead < PLAYER * 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[11].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[0].width;
}
