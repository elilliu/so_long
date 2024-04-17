/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_chest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:02:57 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/19 00:21:52 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_on_chest(t_data *data, char c)
{
	data->player_on_chest = 1;
	if (c == 'C')
		data->chests_found++;
}
