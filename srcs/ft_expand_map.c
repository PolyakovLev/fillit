/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:08:57 by daharwoo          #+#    #+#             */
/*   Updated: 2018/12/18 20:49:52 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_make_parse(int size)
{
	int		i;
	char	*to_parse;

	i = 0;
	to_parse = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		to_parse[i] = '.';
		i++;
	}
	to_parse[i] = '\0';
	return (to_parse);
}

char		**ft_expand_map(char **map)
{
	int		i;
	int		new_size;
	char	**expanded_map;

	i = 0;
	new_size = (int)ft_strlen(map[0]) + 1;
	expanded_map = (char **)malloc(sizeof(char *) * (new_size + 2));
	while (i < new_size)
	{
		expanded_map[i] = ft_make_parse(new_size);
		i++;
	}
	expanded_map[i] = NULL;
	ft_strstrdel(map);
	return (expanded_map);
}
