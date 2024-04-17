/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_banner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:38:43 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 18:53:42 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_unit2(t_data *data, char nb, int x)
{
	if (nb == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[5].ptr, x, 0);
	if (nb == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[6].ptr, x, 0);
	if (nb == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[7].ptr, x, 0);
	if (nb == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[8].ptr, x, 0);
	if (nb == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[9].ptr, x, 0);
	return (1);
}

int	put_unit(t_data *data, char nb, int pos)
{
	int	x;

	x = (data->map.length - pos) * 32;
	if (nb == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[0].ptr, x, 0);
	else if (nb == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[1].ptr, x, 0);
	else if (nb == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[2].ptr, x, 0);
	else if (nb == '3')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[3].ptr, x, 0);
	else if (nb == '4')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->counter[4].ptr, x, 0);
	else
		put_unit2(data, nb, x);
	return (1);
}

int	put_move_count(t_data *data)
{
	char	*move_counter;

	move_counter = ft_itoa(data->move_count);
	if (data->move_count > 99)
	{
		put_unit(data, move_counter[0], 3);
		put_unit(data, move_counter[1], 2);
		put_unit(data, move_counter[2], 1);
	}
	else if (data->move_count > 9)
	{
		put_unit(data, '0', 3);
		put_unit(data, move_counter[0], 2);
		put_unit(data, move_counter[1], 1);
	}
	else
	{
		put_unit(data, '0', 3);
		put_unit(data, '0', 2);
		put_unit(data, move_counter[0], 1);
	}
	free(move_counter);
	return (1);
}

int	put_banner(t_data *data)
{
	data->x_to_fill = 0;
	data->y_to_fill = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->basic_tiles[4].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[4].width;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->basic_tiles[5].ptr, data->x_to_fill, data->y_to_fill);
	data->x_to_fill += data->basic_tiles[5].width;
	while (data->x_to_fill < (data->map.length - 3) * 32)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->basic_tiles[6].ptr, data->x_to_fill, data->y_to_fill);
		data->x_to_fill += data->basic_tiles[6].width;
	}
	put_move_count(data);
	data->x_to_fill = 0;
	return (1);
}
