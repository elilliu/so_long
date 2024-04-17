/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:44:08 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/25 18:22:47 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
0. RIGHT
1. right
2. LEFT
3. left
4. BACK
5. back
6. FRONT
7. front
8. d1
9. d2
10. d3
11. d4
*/

int	player_init(t_data *data)
{
	data->player = malloc(sizeof(t_img) * 13);
	if (!data->player)
		return (0);
	data->player[0].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/right_big.xpm", &data->player[0].width,
			&data->player[0].height);
	if (!data->player[0].ptr)
		return (ft_free_player(data, 0), 0);
	data->player[1].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/right_small.xpm", &data->player[1].width,
			&data->player[1].height);
	if (!data->player[1].ptr)
		return (ft_free_player(data, 1), 0);
	data->player[2].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/left_big.xpm", &data->player[2].width,
			&data->player[2].height);
	if (!data->player[2].ptr)
		return (ft_free_player(data, 2), 0);
	data->player[3].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/left_small.xpm", &data->player[3].width,
			&data->player[3].height);
	if (!data->player[3].ptr)
		return (ft_free_player(data, 3), 0);
	return (1);
}

int	player_init2(t_data *data)
{
	data->player[4].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/back_big.xpm", &data->player[4].width,
			&data->player[4].height);
	if (!data->player[4].ptr)
		return (ft_free_player(data, 4), 0);
	data->player[5].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/back_small.xpm", &data->player[5].width,
			&data->player[5].height);
	if (!data->player[5].ptr)
		return (ft_free_player(data, 5), 0);
	data->player[6].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/front_big.xpm", &data->player[6].width,
			&data->player[6].height);
	if (!data->player[6].ptr)
		return (ft_free_player(data, 6), 0);
	data->player[7].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/front_small.xpm", &data->player[7].width,
			&data->player[7].height);
	if (!data->player[7].ptr)
		return (ft_free_player(data, 7), 0);
	return (1);
}

int	player_init3(t_data *data)
{
	data->player[8].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player_death/d1.xpm", &data->player[8].width,
			&data->player[8].height);
	if (!data->player[8].ptr)
		return (ft_free_player(data, 8), 0);
	data->player[9].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player_death/d2.xpm", &data->player[9].width,
			&data->player[9].height);
	if (!data->player[9].ptr)
		return (ft_free_player(data, 9), 0);
	data->player[10].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player_death/d3.xpm", &data->player[10].width,
			&data->player[10].height);
	if (!data->player[10].ptr)
		return (ft_free_player(data, 10), 0);
	data->player[11].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player_death/d4.xpm", &data->player[11].width,
			&data->player[11].height);
	if (!data->player[11].ptr)
		return (ft_free_player(data, 11), 0);
	return (1);
}
