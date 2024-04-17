/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_zombies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:45:32 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/26 18:38:50 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_obstacle(char c)
{
	if (c == '1' || c == 'E' || c == 'C' || c == 'O' || c == 'S')
		return (1);
	return (0);
}

void	move_zombie_left(t_data *data, int row, int i)
{
	char	b;
	char	d;

	b = data->map.tab[row][i + 1];
	d = data->map.tab[row][i - 1];
	if (d == 'P' || d == 'L' || d == 'R' || d == 'B')
		data->player_dead++;
	else if (is_obstacle(d) == 1)
	{
		if (b == 'P' || d == 'L' || d == 'R' || d == 'B')
			data->player_dead++;
		else if (b == '0')
		{
			data->map.tab[row][i] = '0';
			data->map.tab[row][i + 1] = 'Z';
		}
		else
			data->map.tab[row][i] = 'Z';
	}
	else
	{
		data->map.tab[row][i] = '0';
		data->map.tab[row][i - 1] = 'z';
	}
}

void	move_zombie_right(t_data *data, int row, int i)
{
	char	b;
	char	d;

	b = data->map.tab[row][i - 1];
	d = data->map.tab[row][i + 1];
	if (d == 'P' || d == 'L' || d == 'R' || d == 'B')
		data->player_dead++;
	else if (is_obstacle(d) == 1)
	{
		if (b == 'P' || d == 'L' || d == 'R' || d == 'B')
			data->player_dead++;
		else if (b == '0')
		{
			data->map.tab[row][i] = '0';
			data->map.tab[row][i - 1] = 'z';
		}
		else
			data->map.tab[row][i] = 'z';
	}
	else
	{
		data->map.tab[row][i] = '0';
		data->map.tab[row][i + 1] = 'Z';
	}
}

void	move_zombies(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'Z')
			{
				move_zombie_right(data, row, i);
				break ;
			}
			else if (data->map.tab[row][i] == 'z')
			{
				move_zombie_left(data, row, i);
				break ;
			}
			i++;
		}
		row++;
	}
}
