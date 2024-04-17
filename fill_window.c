/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:31:18 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 18:50:32 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_window(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	data->x_to_fill = 0;
	data->y_to_fill = 32;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			fill_window_utils(data, data->map.tab[row][i]);
			i++;
		}
		data->y_to_fill += data->basic_tiles[1].height;
		data->x_to_fill = 0;
		row++;
	}
	return (1);
}
