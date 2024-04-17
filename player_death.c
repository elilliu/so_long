/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:20:24 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/26 17:16:33 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_death(t_data *data)
{
	int	row;
	int	i;

	if (data->player_dead == DEATH * 4)
		clean_all(data);
	row = 0;
	if (data->player_dead == 1)
	{
		while (row < data->map.rows)
		{
			i = 0;
			while (data->map.tab[row][i])
			{
				if (data->map.tab[row][i] == 'P' || data->map.tab[row][i] == 'B'
					|| data->map.tab[row][i] == 'L'
					|| data->map.tab[row][i] == 'R')
					data->map.tab[row][i] = 'X';
				i++;
			}
			row++;
		}
	}
	put_banner(data);
	fill_window(data);
	data->player_dead++;
}
