/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:27:40 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/24 17:28:13 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_exit(t_data *data)
{
	data->move_count++;
	printf("Total moves: %d\n", data->move_count);
	clean_all(data);
}
