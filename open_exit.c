/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:06:43 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/19 00:10:45 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'E')
				data->map.tab[row][i] = 'S';
			i++;
		}
		row++;
	}
	data->chests_found++;
}
