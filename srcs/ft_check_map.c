/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:10:39 by daharwoo          #+#    #+#             */
/*   Updated: 2018/12/18 20:47:42 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_check_rows(t_figure_list *figure, char **map, int y)
{
	if (!map[figure->rows[0] + y] ||
		!map[figure->rows[1] + y] ||
		!map[figure->rows[2] + y] ||
		!map[figure->rows[3] + y])
		return (0);
	return (1);
}

int				ft_check_cols(t_figure_list *figure, char **map, int x, int y)
{
	if (ft_check_rows(figure, map, y))
	{
		if (map[figure->rows[0] + y][figure->cols[0] + x] &&
			map[figure->rows[1] + y][figure->cols[1] + x] &&
			map[figure->rows[2] + y][figure->cols[2] + x] &&
			map[figure->rows[3] + y][figure->cols[3] + x])
			return (1);
	}
	return (0);
}

static int		ft_check_map(t_figure_list *figure, char **map, int x, int y)
{
	if (!ft_check_cols(figure, map, x, y) ||
		!ft_check_rows(figure, map, y))
		return (0);
	return (1);
}

int				ft_find_dots(t_figure_list *figure, char **map, int x, int y)
{
	if (ft_check_map(figure, map, x, y))
	{
		if (map[figure->rows[0] + y][figure->cols[0] + x] == '.' &&
			map[figure->rows[1] + y][figure->cols[1] + x] == '.' &&
			map[figure->rows[2] + y][figure->cols[2] + x] == '.' &&
			map[figure->rows[3] + y][figure->cols[3] + x] == '.')
			return (1);
	}
	return (0);
}
