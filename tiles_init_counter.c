/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_init_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:03:28 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 18:32:48 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter_init(t_data *data)
{
	data->counter = malloc(sizeof(t_img) * 11);
	if (!data->counter)
		return (0);
	data->counter[0].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/zero.xpm", &data->counter[0].width,
			&data->counter[0].height);
	if (!data->counter[0].ptr)
		return (ft_free_counter(data, 0), 0);
	data->counter[1].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/one.xpm", &data->counter[1].width,
			&data->counter[1].height);
	if (!data->counter[1].ptr)
		return (ft_free_counter(data, 1), 0);
	data->counter[2].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/two.xpm", &data->counter[2].width,
			&data->counter[2].height);
	if (!data->counter[2].ptr)
		return (ft_free_counter(data, 2), 0);
	data->counter[3].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/three.xpm", &data->counter[3].width,
			&data->counter[3].height);
	if (!data->counter[3].ptr)
		return (ft_free_counter(data, 3), 0);
	return (1);
}

int	counter_init2(t_data *data)
{
	data->counter[4].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/four.xpm", &data->counter[4].width,
			&data->counter[4].height);
	if (!data->counter[4].ptr)
		return (ft_free_counter(data, 4), 0);
	data->counter[5].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/five.xpm", &data->counter[5].width,
			&data->counter[5].height);
	if (!data->counter[5].ptr)
		return (ft_free_counter(data, 5), 0);
	data->counter[6].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/six.xpm", &data->counter[6].width,
			&data->counter[6].height);
	if (!data->counter[6].ptr)
		return (ft_free_counter(data, 6), 0);
	data->counter[7].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/seven.xpm", &data->counter[7].width,
			&data->counter[7].height);
	if (!data->counter[7].ptr)
		return (ft_free_counter(data, 7), 0);
	return (1);
}

int	counter_init3(t_data *data)
{
	data->counter[8].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/eight.xpm", &data->counter[8].width,
			&data->counter[8].height);
	if (!data->counter[8].ptr)
		return (ft_free_counter(data, 8), 0);
	data->counter[9].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/counter/nine.xpm", &data->counter[9].width,
			&data->counter[9].height);
	if (!data->counter[9].ptr)
		return (ft_free_counter(data, 9), 0);
	return (1);
}
