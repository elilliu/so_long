/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:05:40 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/21 17:46:49 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_fill_tab(int row, t_data *data, char *line, int fd)
{
	while (row >= 0)
		free(data->map.tab[row--]);
	if (line)
		free(line);
	close(fd);
	return (1);
}

int	fill_tab(t_data *data)
{
	t_fill_tab	ft;

	ft.i = 0;
	ft.row = 0;
	ft.fd = open(data->map_path, O_RDONLY);
	ft.line = NULL;
	while (ft.row < data->map.rows)
	{
		data->map.tab[ft.row] = malloc(sizeof(char) * (data->map.length + 1));
		if (!data->map.tab[ft.row])
			return (free_fill_tab(ft.row, data, ft.line, ft.fd), 0);
		ft.line = get_next_line(ft.fd);
		ft.i = -1;
		while (ft.line [++ft.i] && ft.line[ft.i] != '\n')
			data->map.tab[ft.row][ft.i] = ft.line[ft.i];
		free(ft.line);
		data->map.tab[ft.row][ft.i] = '\0';
		ft.row++;
	}
	data->map.tab[ft.row] = NULL;
	close(ft.fd);
	return (1);
}

int	map_init(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Failed to open file\n", 2), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line[data->map.length] && line[data->map.length] != '\n')
		data->map.length++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map.rows++;
	}
	close(fd);
	free(line);
	data->map.tab = malloc(sizeof(char *) * (data->map.rows + 1));
	if (!data->map.tab)
		return (0);
	if (fill_tab(data) == 0)
		return (free(data->map.tab), 0);
	return (1);
}
