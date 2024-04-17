/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:14:51 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 15:01:02 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_basic_tiles(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		mlx_destroy_image(data->mlx_ptr, data->basic_tiles[i].ptr);
		i++;
	}
	free(data->basic_tiles);
}

void	ft_free_counter(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		mlx_destroy_image(data->mlx_ptr, data->counter[i].ptr);
		i++;
	}
	free(data->counter);
}

void	ft_free_exit(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		mlx_destroy_image(data->mlx_ptr, data->exit[i].ptr);
		i++;
	}
	free(data->exit);
}

void	ft_free_player(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		mlx_destroy_image(data->mlx_ptr, data->player[i].ptr);
		i++;
	}
	free(data->player);
}

void	ft_free_zombie(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		mlx_destroy_image(data->mlx_ptr, data->zombie[i].ptr);
		i++;
	}
	free(data->zombie);
}
