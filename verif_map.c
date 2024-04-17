/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:14 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:59:02 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_chests(t_list *verif, t_data *data)
{
	int	x;
	int	y;
	int	chests;
	int	player;

	chests = 0;
	player = 0;
	while (verif)
	{
		x = verif->x;
		y = verif->y;
		if (data->map.tab[y][x] == 'C')
			chests++;
		else if (data->map.tab[y][x] == 'P')
			player++;
		verif = verif->next;
	}
	if (chests != data->chest_nb || player != 1)
		return (0);
	return (1);
}

void	find_path(t_data *data, t_list **verif, int x, int y)
{
	if (available_tile(data, x + 1, y) == 1
		&& new_coordinates(*verif, x + 1, y) == 1)
	{
		ft_lstadd_back(verif, ft_lstnew(x + 1, y));
		find_path(data, verif, x + 1, y);
	}
	if (available_tile(data, x, y + 1) == 1
		&& new_coordinates(*verif, x, y + 1) == 1)
	{
		ft_lstadd_back(verif, ft_lstnew(x, y + 1));
		find_path(data, verif, x, y + 1);
	}
	if (available_tile(data, x - 1, y) == 1
		&& new_coordinates(*verif, x - 1, y) == 1)
	{
		ft_lstadd_back(verif, ft_lstnew(x - 1, y));
		find_path(data, verif, x - 1, y);
	}
	if (available_tile(data, x, y - 1) == 1
		&& new_coordinates(*verif, x, y - 1) == 1)
	{
		ft_lstadd_back(verif, ft_lstnew(x, y - 1));
		find_path(data, verif, x, y - 1);
	}
}

int	count_exit(t_data *data)
{
	int	row;
	int	i;
	int	exit;
	int	player;

	row = 0;
	exit = 0;
	player = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'E')
				exit++;
			else if (data->map.tab[row][i] == 'P')
				player++;
			i++;
		}
		row++;
	}
	if (exit != 1 || player != 1)
		return (0);
	return (1);
}

int	verif_map(t_data *data)
{
	t_list	*verif;

	if (verif_elements(data) == 0)
		return (ft_putstr_fd("Error: Unidentified element in map\n", 2), 0);
	if (verif_zombies(data) == 0)
		return (ft_putstr_fd("Error: Please put one zombie per line\n", 2), 0);
	if (verif_border(data) == 0 || verif_largeur(data) == 0)
		return (ft_putstr_fd("Error: Map must be a rectangle\n"
				"Map must be surrounded by walls\n", 2), 0);
	verif = ft_lstnew(data->player_x, data->player_y);
	if (!verif)
		return (0);
	find_path(data, &verif, data->player_x, data->player_y);
	if (count_exit(data) == 0)
		return (ft_putstr_fd("Error: Please put one exit and one player\n", 2),
			ft_lstclear(&verif), 0);
	if (find_exit(verif, data) == 0)
		return (ft_putstr_fd("Error: Exit must be reachable\n", 2),
			ft_lstclear(&verif), 0);
	if (find_chests(verif, data) == 0)
		return (ft_putstr_fd("Error: All chests must be reacheable\n", 2),
			ft_lstclear(&verif), 0);
	ft_lstclear(&verif);
	return (1);
}
