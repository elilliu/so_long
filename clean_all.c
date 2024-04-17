/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:08 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 14:34:14 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_data *data)
{
	int	row;

	row = 0;
	while (row < data->map.rows)
		free (data->map.tab[row++]);
	free (data->map.tab);
}

void	destroy_all_tiles(t_data *data)
{
	ft_free_basic_tiles(data, 6);
	ft_free_counter(data, 9);
	ft_free_exit(data, 4);
	ft_free_player(data, 11);
	ft_free_zombie(data, 7);
}

void	clean_data(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab(data);
	free(data->map_path);
}

int	clean_all(t_data *data)
{
	destroy_all_tiles(data);
	clean_data(data);
	exit (0);
}
