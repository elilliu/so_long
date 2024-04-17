/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:02:01 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:45:32 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall_floor(t_data *data, char c)
{
	if (c == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->basic_tiles[1].ptr, data->x_to_fill, data->y_to_fill);
		data->x_to_fill += data->basic_tiles[1].width;
	}
	else if (c == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->basic_tiles[0].ptr, data->x_to_fill, data->y_to_fill);
		data->x_to_fill += data->basic_tiles[0].width;
	}
}

void	put_player(t_data *data, char c)
{
	if (c == 'P' && data->player_timer < PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[6].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'P' && data->player_timer < PLAYER * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[7].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'L' && data->player_timer < PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[2].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'L' && data->player_timer < PLAYER * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[3].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'R' && data->player_timer < PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[0].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'R' && data->player_timer < PLAYER * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[1].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'B' && data->player_timer < PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[4].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'B' && data->player_timer < PLAYER * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player[5].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[0].width;
}

void	put_chest(t_data *data, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->basic_tiles[2].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'O')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->basic_tiles[3].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[0].width;
}

void	put_exit(t_data *data, char c)
{
	if (c == 'E' && data->exit_timer < EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit[0].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'E' && data->exit_timer < EXIT * 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit[1].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'E' && data->exit_timer < EXIT * 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit[2].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'E' && data->exit_timer < EXIT * 4)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit[3].ptr, data->x_to_fill, data->y_to_fill);
	else if (c == 'S')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit[4].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[0].width;
}

void	fill_window_utils(t_data *data, char c)
{
	if (c == '1' || c == '0')
		put_wall_floor(data, c);
	else if (c == 'P' || c == 'L' || c == 'R' || c == 'B')
		put_player(data, c);
	else if (c == 'C' || c == 'O')
		put_chest(data, c);
	else if (c == 'E' || c == 'S')
		put_exit(data, c);
	else if (c == 'Z')
		put_zombie_right(data);
	else if (c == 'z')
		put_zombie_left(data);
	else if (c == 'X')
		put_player_death(data);
}
