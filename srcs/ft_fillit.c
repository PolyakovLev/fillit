/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:07:19 by ramory-l          #+#    #+#             */
/*   Updated: 2018/12/18 20:50:32 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_reset(t_figure_list *figure, char **map, int x, int y)
{
	map[figure->rows[0] + y][figure->cols[0] + x] = '.';
	map[figure->rows[1] + y][figure->cols[1] + x] = '.';
	map[figure->rows[2] + y][figure->cols[2] + x] = '.';
	map[figure->rows[3] + y][figure->cols[3] + x] = '.';
}

static void	ft_set(t_figure_list *figure, t_map mapis, int x, int y)
{
	mapis.map[figure->rows[0] + y][figure->cols[0] + x] = mapis.i;
	mapis.map[figure->rows[1] + y][figure->cols[1] + x] = mapis.i;
	mapis.map[figure->rows[2] + y][figure->cols[2] + x] = mapis.i;
	mapis.map[figure->rows[3] + y][figure->cols[3] + x] = mapis.i;
}

int			ft_try(t_figure_list *figure, char **map, int x, int y)
{
	int			result;
	t_map		mapis;
	static char i = 'A';

	result = 0;
	mapis.i = i;
	mapis.map = map;
	if (ft_find_dots(figure, map, x, y) && i++)
	{
		ft_set(figure, mapis, x, y);
		if (figure->next != NULL)
		{
			if (!(result = ft_try(figure->next, map, 0, 0)) && i--)
				ft_reset(figure, map, x, y);
		}
		else
			return (1);
	}
	if (result)
		return (result);
	if (ft_check_cols(figure, map, x + 1, y))
		result = ft_try(figure, map, x + 1, y);
	else if (ft_check_rows(figure, map, y + 1))
		result = ft_try(figure, map, 0, y + 1);
	return (result);
}
