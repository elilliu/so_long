/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:09:28 by elilliu           #+#    #+#             */
/*   Updated: 2024/03/28 16:57:51 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define ZOMBIE 300
# define PLAYER 200
# define DEATH 200
# define EXIT 100

typedef struct s_fill_tab
{
	int		fd;
	int		i;
	int		row;
	char	*line;
}			t_fill_tab;

typedef struct s_map
{
	char	**tab;
	int		rows;
	int		length;
}			t_map;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}			t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*map_path;
	int			x_to_fill;
	int			y_to_fill;
	int			player_x;
	int			player_y;
	int			chest_nb;
	int			chests_found;
	int			player_on_chest;
	int			move_count;
	int			timer;
	int			player_timer;
	int			exit_timer;
	int			player_dead;
	t_map		map;
	t_img		*basic_tiles;
	t_img		*zombie;
	t_img		*player;
	t_img		*exit;
	t_img		*counter;
}				t_data;

typedef struct s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}					t_list;

int		main(int ac, char **av);
int		fill_window(t_data *data);
int		map_init(t_data *data);
int		data_init(t_data *data, char *str);
int		data_init2(t_data *data);
int		tiles_init(t_data *data);
int		basic_tiles_init(t_data *data);
int		basic_tiles_init2(t_data *data);
int		counter_init(t_data *data);
int		counter_init2(t_data *data);
int		counter_init3(t_data *data);
int		exit_init(t_data *data);
int		exit_init2(t_data *data);
int		player_init(t_data *data);
int		player_init2(t_data *data);
int		player_init3(t_data *data);
int		zombie_init(t_data *data);
int		zombie_init2(t_data *data);
void	player_chests_init(t_data *data);
void	fill_window_utils(t_data *data, char c);
int		clean_all(t_data *data);
void	move_down(t_data *data, int x, int y);
void	move_left(t_data *data, int x, int y);
void	move_right(t_data *data, int x, int y);
void	move_up(t_data *data, int x, int y);
void	player_on_chest(t_data *data, char c);
void	open_exit(t_data *data);
void	player_exit(t_data *data);
void	move_zombies(t_data *data);
t_list	*ft_lstnew(int x, int y);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		new_coordinates(t_list *verif, int x, int y);
int		available_tile(t_data *data, int x, int y);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_putstr_fd(char *s, int fd);
int		verif_zombies(t_data *data);
int		verif_border(t_data *data);
int		verif_largeur(t_data *data);
int		verif_elements(t_data *data);
void	free_tab(t_data *data);
int		verif_map(t_data *data);
int		find_exit(t_list *verif, t_data *data);
int		put_banner(t_data *data);
void	player_death(t_data *data);
char	*ft_itoa(int n);
void	ft_free_counter(t_data *data, int nb);
void	clean_data(t_data *data);
void	ft_free_basic_tiles(t_data *data, int nb);
void	ft_free_counter(t_data *data, int nb);
void	ft_free_exit(t_data *data, int nb);
void	ft_free_player(t_data *data, int nb);
void	ft_free_zombie(t_data *data, int nb);
void	put_zombie_right(t_data *data);
void	put_zombie_left(t_data *data);
void	put_player_death(t_data *data);

#endif
