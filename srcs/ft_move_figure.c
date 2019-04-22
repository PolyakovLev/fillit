/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:54:27 by ramory-l          #+#    #+#             */
/*   Updated: 2018/12/18 20:51:14 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_move_up(t_figure_list *figure)
{
	while (figure->rows[0] && figure->rows[1] &&
			figure->rows[2] && figure->rows[3])
	{
		figure->rows[0] -= 1;
		figure->rows[1] -= 1;
		figure->rows[2] -= 1;
		figure->rows[3] -= 1;
	}
}

static void		ft_move_left(t_figure_list *figure)
{
	while (figure->cols[0] && figure->cols[1] &&
			figure->cols[2] && figure->cols[3])
	{
		figure->cols[0] -= 1;
		figure->cols[1] -= 1;
		figure->cols[2] -= 1;
		figure->cols[3] -= 1;
	}
}

void			ft_move_figure(t_figure_list *figure)
{
	ft_move_left(figure);
	ft_move_up(figure);
}
