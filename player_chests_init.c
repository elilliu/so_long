/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_chests_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:38:50 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/19 00:28:44 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_chests_init(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	i = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'P')
			{
				data->player_x = i;
				data->player_y = row;
			}
			if (data->map.tab[row][i] == 'C')
				data->chest_nb++;
			i++;
		}
		row++;
	}
	data->chests_found = 0;
}
