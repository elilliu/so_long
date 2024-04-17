/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:38:19 by elilliu           #+#    #+#             */
/*   Updated: 2024/01/25 18:29:12 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

int	access_exit(t_list *verif, int row, int i)
{
	while (verif)
	{
		if ((verif->x + 1 == i && verif->y == row)
			|| (verif->x == i && verif->y + 1 == row)
			|| (verif->x - 1 == i && verif->y == row)
			|| (verif->x == i && verif->y - 1 == row))
			return (1);
		verif = verif->next;
	}
	return (0);
}

int	find_exit(t_list *verif, t_data *data)
{
	int	row;
	int	i;

	row = 0;
	while (row < data->map.rows)
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'E')
				break ;
			i++;
		}
		if (data->map.tab[row][i] == 'E')
			break ;
		row++;
	}
	if (access_exit(verif, row, i) == 0)
		return (0);
	return (1);
}
