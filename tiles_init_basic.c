/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_init_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:17:53 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 15:00:49 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
0. floor
1. wall
2. closed chest
3. opened chest
4. zombie print
5. game print
6. banner background
*/

int	basic_tiles_init(t_data *data)
{
	data->basic_tiles = malloc(sizeof(t_img) * 8);
	if (!data->basic_tiles)
		return (0);
	data->basic_tiles[0].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/floor.xpm", &data->basic_tiles[0].width,
			&data->basic_tiles[0].height);
	if (!data->basic_tiles[0].ptr)
		return (ft_free_basic_tiles(data, 0), 0);
	data->basic_tiles[1].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &data->basic_tiles[1].width,
			&data->basic_tiles[1].height);
	if (!data->basic_tiles[1].ptr)
		return (ft_free_basic_tiles(data, 1), 0);
	data->basic_tiles[2].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/chest_closed.xpm", &data->basic_tiles[2].width,
			&data->basic_tiles[2].height);
	if (!data->basic_tiles[2].ptr)
		return (ft_free_basic_tiles(data, 2), 0);
	data->basic_tiles[3].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/chest_opened.xpm", &data->basic_tiles[3].width,
			&data->basic_tiles[3].height);
	if (!data->basic_tiles[3].ptr)
		return (ft_free_basic_tiles(data, 2), 0);
	return (1);
}

int	basic_tiles_init2(t_data *data)
{
	data->basic_tiles[4].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/zombie_print.xpm", &data->basic_tiles[4].width,
			&data->basic_tiles[4].height);
	if (!data->basic_tiles[4].ptr)
		return (ft_free_basic_tiles(data, 4), 0);
	data->basic_tiles[5].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/game.xpm", &data->basic_tiles[5].width,
			&data->basic_tiles[5].height);
	if (!data->basic_tiles[5].ptr)
		return (ft_free_basic_tiles(data, 5), 0);
	data->basic_tiles[6].ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/banner_background.xpm", &data->basic_tiles[6].width,
			&data->basic_tiles[6].height);
	if (!data->basic_tiles[6].ptr)
		return (ft_free_basic_tiles(data, 6), 0);
	return (1);
}
