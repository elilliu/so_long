/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:41:41 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:59:38 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_elements(t_data *data)
{
	int	row;
	int	i;
	int	c;

	row = 0;
	i = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			c = data->map.tab[row][i];
			if (c != '1' && c != '0' && c != 'P' && c != 'E'
				&& c != 'z' && c != 'Z' && c != 'C')
				return (0);
			i++;
		}
		row++;
	}
	return (1);
}

int	verif_largeur(t_data *data)
{
	int	row;
	int	i;
	int	largeur;

	row = 0;
	largeur = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
			i++;
		if (largeur == 0)
			largeur = i;
		if (i != largeur)
			return (0);
		row++;
	}
	return (1);
}

int	verif_border2(t_data *data, int row, int i)
{
	row--;
	while (i >= 0)
	{
		if (data->map.tab[row][i] != '1')
			return (0);
		i--;
	}
	i++;
	while (row >= 0)
	{
		if (data->map.tab[row][i] != '1')
			return (0);
		row--;
	}
	return (1);
}

int	verif_border(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	i = 0;
	while (data->map.tab[row][i])
	{
		if (data->map.tab[row][i] != '1')
			return (0);
		i++;
	}
	i--;
	while (row < data->map.rows)
	{
		if (data->map.tab[row][i] != '1')
			return (0);
		row++;
	}
	if (verif_border2(data, row, i) == 0)
		return (0);
	return (1);
}

int	verif_zombies(t_data *data)
{
	int	row;
	int	i;
	int	zombie;

	row = 0;
	while (row < data->map.rows)
	{
		i = 0;
		zombie = 0;
		while (data->map.tab[row][i])
		{
			if ((data->map.tab[row][i] == 'z' || data->map.tab[row][i] == 'Z')
				&& zombie == 1)
				return (0);
			if (data->map.tab[row][i] == 'Z' || data->map.tab[row][i] == 'z')
				zombie++;
			i++;
		}
		row++;
	}
	return (1);
}
