/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:45:59 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 18:45:35 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tiles_init(t_data *data)
{
	if (basic_tiles_init(data) == 0 || basic_tiles_init2(data) == 0)
		return (0);
	if (counter_init(data) == 0 || counter_init2(data) == 0
		|| counter_init3(data) == 0)
		return (ft_free_basic_tiles(data, 6), 0);
	if (exit_init(data) == 0 || exit_init2(data) == 0)
		return (ft_free_basic_tiles(data, 6), ft_free_counter(data, 9), 0);
	if (player_init(data) == 0 || player_init2(data) == 0
		|| player_init3(data) == 0)
		return (ft_free_basic_tiles(data, 6), ft_free_counter(data, 9),
			ft_free_exit(data, 3), 0);
	if (zombie_init(data) == 0 || zombie_init2(data) == 0)
		return (ft_free_basic_tiles(data, 6), ft_free_counter(data, 9),
			ft_free_exit(data, 3), ft_free_player(data, 11), 0);
	return (1);
}
