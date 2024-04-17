/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:06:24 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:58:14 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
		return (0);
	return (1);
}

int	render(t_data *data)
{
	if (data->player_dead > 0)
		return (player_death(data), 0);
	if (data->chests_found == data->chest_nb)
	{
		if (data->exit_timer == 4 * EXIT)
			open_exit(data);
		data->exit_timer++;
	}
	if (data->timer == ZOMBIE * 4 + 1)
		data->timer = 0;
	if (data->timer == ZOMBIE || data->timer == 2 * ZOMBIE
		|| data->timer == 3 * ZOMBIE || data->timer == 4 * ZOMBIE)
		move_zombies(data);
	if (data->player_timer == 2 * PLAYER)
		data->player_timer = 0;
	put_banner(data);
	fill_window(data);
	data->timer++;
	data->player_timer++;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		clean_all(data);
	if (keysym == XK_d)
		move_right(data, data->player_x, data->player_y);
	if (keysym == XK_a)
		move_left(data, data->player_x, data->player_y);
	if (keysym == XK_w)
		move_up(data, data->player_x, data->player_y);
	if (keysym == XK_s)
		move_down(data, data->player_x, data->player_y);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("Please follow this format:"
				" ./so_long map_path\n", 2), 1);
	if (verif_path(av[1]) == 0)
		return (ft_putstr_fd("Map must be a .ber type file\n", 2), 1);
	if (data_init(&data, av[1]) == 0)
		return (1);
	if (data_init2(&data) == 0)
		return (1);
	if (tiles_init(&data) == 0)
		return (ft_putstr_fd("An error has occurred while"
				" creating the tiles\n", 2), clean_data(&data), 1);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&clean_all, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
