/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:17 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:57:27 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_path(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	data->map_path = malloc(sizeof(char) * (i + 1));
	if (!data->map_path)
		return (0);
	i = 0;
	while (str[i])
	{
		data->map_path[i] = str[i];
		i++;
	}
	data->map_path[i] = '\0';
	return (1);
}

int	data_init2(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32,
			data->map.rows * 32 + 32, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	return (1);
}

int	data_init(t_data *data, char *str)
{
	if (map_path(data, str) == 0)
		return (0);
	data->map.rows = 0;
	data->map.length = 0;
	data->x_to_fill = 0;
	data->y_to_fill = 0;
	data->player_on_chest = 0;
	data->move_count = 0;
	data->timer = 0;
	data->player_timer = 0;
	data->exit_timer = 0;
	data->chest_nb = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->chests_found = 0;
	data->player_dead = 0;
	if (map_init(data) == 0)
		return (free(data->map_path), 0);
	player_chests_init(data);
	if (data->player_x == 0 || data->player_y == 0)
		return (ft_putstr_fd("Please put one player on the map\n", 2),
			free_tab(data), free(data->map_path), 0);
	if (verif_map(data) == 0)
		return (free_tab(data), free(data->map_path), 0);
	return (1);
}
