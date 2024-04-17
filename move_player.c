/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:57 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/26 14:43:10 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int x, int y)
{
	if (data->map.tab[y - 1][x] == '1' || data->map.tab[y - 1][x] == 'E')
	{
		data->map.tab[y][x] = 'B';
		return ;
	}
	if (data->map.tab[y - 1][x] == 'Z' || data->map.tab[y - 1][x] == 'z')
	{
		data->player_dead++;
		return ;
	}
	if (data->player_on_chest == 1)
		data->map.tab[y][x] = 'O';
	else
		data->map.tab[y][x] = '0';
	if (data->map.tab[y - 1][x] == 'C' || data->map.tab[y - 1][x] == 'O')
		player_on_chest(data, data->map.tab[y - 1][x]);
	else if (data->map.tab[y - 1][x] == 'S')
		player_exit(data);
	else
		data->player_on_chest = 0;
	data->map.tab[y - 1][x] = 'B';
	data->player_y = y - 1;
	data->player_timer = 0;
	data->move_count++;
}

void	move_down(t_data *data, int x, int y)
{
	if (data->map.tab[y + 1][x] == '1' || data->map.tab[y + 1][x] == 'E')
	{
		data->map.tab[y][x] = 'P';
		return ;
	}
	if (data->map.tab[y + 1][x] == 'Z' || data->map.tab[y + 1][x] == 'z')
	{
		data->player_dead++;
		return ;
	}
	if (data->player_on_chest == 1)
		data->map.tab[y][x] = 'O';
	else
		data->map.tab[y][x] = '0';
	if (data->map.tab[y + 1][x] == 'C' || data->map.tab[y + 1][x] == 'O')
		player_on_chest(data, data->map.tab[y + 1][x]);
	else if (data->map.tab[y + 1][x] == 'S')
		player_exit(data);
	else
		data->player_on_chest = 0;
	data->map.tab[y + 1][x] = 'P';
	data->player_y = y + 1;
	data->player_timer = 0;
	data->move_count++;
}

void	move_right(t_data *data, int x, int y)
{
	if (data->map.tab[y][x + 1] == '1' || data->map.tab[y][x + 1] == 'E')
	{
		data->map.tab[y][x] = 'R';
		return ;
	}
	if (data->map.tab[y][x + 1] == 'Z' || data->map.tab[y][x + 1] == 'z')
	{
		data->player_dead++;
		return ;
	}
	if (data->player_on_chest == 1)
		data->map.tab[y][x] = 'O';
	else
		data->map.tab[y][x] = '0';
	if (data->map.tab[y][x + 1] == 'C' || data->map.tab[y][x + 1] == 'O')
		player_on_chest(data, data->map.tab[y][x + 1]);
	else if (data->map.tab[y][x + 1] == 'S')
		player_exit(data);
	else
		data->player_on_chest = 0;
	data->map.tab[y][x + 1] = 'R';
	data->player_x = x + 1;
	data->player_timer = 0;
	data->move_count++;
}

void	move_left(t_data *data, int x, int y)
{
	if (data->map.tab[y][x - 1] == '1' || data->map.tab[y][x - 1] == 'E')
	{
		data->map.tab[y][x] = 'L';
		return ;
	}
	if (data->map.tab[y][x - 1] == 'Z' || data->map.tab[y][x - 1] == 'z')
	{
		data->player_dead++;
		return ;
	}
	if (data->player_on_chest == 1)
		data->map.tab[y][x] = 'O';
	else
		data->map.tab[y][x] = '0';
	if (data->map.tab[y][x - 1] == 'C' || data->map.tab[y][x - 1] == 'O')
		player_on_chest(data, data->map.tab[y][x - 1]);
	else if (data->map.tab[y][x - 1] == 'S')
		player_exit(data);
	else
		data->player_on_chest = 0;
	data->map.tab[y][x - 1] = 'L';
	data->player_x = x - 1;
	data->player_timer = 0;
	data->move_count++;
}
