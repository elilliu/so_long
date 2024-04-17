/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:35:30 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 17:51:47 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
0. closed
1. opening1
2. opening2
3. opening3
4. opened
*/

int	exit_init2(t_data *data)
{
	data->exit[4].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/opened.xpm", &data->exit[4].width,
			&data->exit[4].height);
	if (!data->exit[4].ptr)
		return (ft_free_exit(data, 4), 0);
	return (1);
}

int	exit_init(t_data *data)
{
	data->exit = malloc(sizeof(t_img) * 6);
	if (!data->exit)
		return (0);
	data->exit[0].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/closed.xpm", &data->exit[0].width,
			&data->exit[0].height);
	if (!data->exit[0].ptr)
		return (ft_free_exit(data, 0), 0);
	data->exit[1].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/opening1.xpm", &data->exit[1].width,
			&data->exit[1].height);
	if (!data->exit[1].ptr)
		return (ft_free_exit(data, 1), 0);
	data->exit[2].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/opening2.xpm", &data->exit[2].width,
			&data->exit[2].height);
	if (!data->exit[2].ptr)
		return (ft_free_exit(data, 2), 0);
	data->exit[3].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/opening3.xpm", &data->exit[3].width,
			&data->exit[3].height);
	if (!data->exit[3].ptr)
		return (ft_free_exit(data, 3), 0);
	return (1);
}
