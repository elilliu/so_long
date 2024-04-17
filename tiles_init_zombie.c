/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_init_zombie.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:31:01 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 18:38:41 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
0. right1
1. right2
2. right3
3. right4
4. left1
5. left2
6. left3
7. left4
*/

int	zombie_init(t_data *data)
{
	data->zombie = malloc(sizeof(t_img) * 9);
	if (!data->zombie)
		return (0);
	data->zombie[0].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_right/zombie_right1.xpm", &data->zombie[0].width,
			&data->zombie[0].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 0), 0);
	data->zombie[1].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_right/zombie_right2.xpm", &data->zombie[1].width,
			&data->zombie[1].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 1), 0);
	data->zombie[2].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_right/zombie_right3.xpm", &data->zombie[2].width,
			&data->zombie[2].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 2), 0);
	data->zombie[3].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_right/zombie_right4.xpm", &data->zombie[3].width,
			&data->zombie[3].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 3), 0);
	return (1);
}

int	zombie_init2(t_data *data)
{
	data->zombie[4].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_left/zombie_left1.xpm", &data->zombie[4].width,
			&data->zombie[4].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 4), 0);
	data->zombie[5].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_left/zombie_left2.xpm", &data->zombie[5].width,
			&data->zombie[5].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 5), 0);
	data->zombie[6].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_left/zombie_left3.xpm", &data->zombie[6].width,
			&data->zombie[6].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 6), 0);
	data->zombie[7].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_left/zombie_left4.xpm", &data->zombie[7].width,
			&data->zombie[7].height);
	if (!data->zombie[0].ptr)
		return (ft_free_zombie(data, 7), 0);
	return (1);
}
