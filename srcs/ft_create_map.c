/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:12:42 by daharwoo          #+#    #+#             */
/*   Updated: 2018/12/18 20:49:37 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_make_parse(t_figure_list *figure)
{
	int		i;
	int		counter;
	char	*to_parse;

	i = 0;
	counter = 0;
	while (figure)
	{
		figure = figure->next;
		counter++;
	}
	counter = ft_sqrt(counter * 4);
	to_parse = (char *)malloc(sizeof(char) * (counter + 1));
	while (i < counter)
	{
		to_parse[i] = '.';
		i++;
	}
	to_parse[i] = '\0';
	return (to_parse);
}

char			**ft_create_map(t_figure_list *figure)
{
	int		i;
	int		size;
	char	**map;
	char	*to_parse;

	i = 0;
	to_parse = ft_make_parse(figure);
	size = (int)ft_strlen(to_parse);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = ft_make_parse(figure);
		i++;
	}
	map[i] = NULL;
	free(to_parse);
	return (map);
}
