/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:25:15 by daharwoo          #+#    #+#             */
/*   Updated: 2018/12/19 15:30:02 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line.h"

typedef struct				s_figure_list
{
	int						rows[4];
	int						cols[4];
	struct s_figure_list	*next;
}							t_figure_list;

typedef struct				s_map
{
	char					**map;
	char					i;
}							t_map;

t_figure_list				*ft_create_list(char *argv);
int							ft_reader(char *argv);
void						ft_move_figure(t_figure_list *figure);
int							ft_find_dots(t_figure_list *figure,
											char **map, int x, int y);
int							ft_try(t_figure_list *figure,
											char **map, int x, int y);
char						**ft_create_map(t_figure_list *figure);
char						**ft_expand_map(char **map);
void						ft_print_map(char **map);
int							ft_check_cols(t_figure_list *figure,
											char **map, int x, int y);
int							ft_check_rows(t_figure_list *figure,
											char **map, int y);
#endif
