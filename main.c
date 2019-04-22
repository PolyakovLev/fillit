/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:41:51 by ramory-l          #+#    #+#             */
/*   Updated: 2018/12/18 20:57:13 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage_msg(const char *prog_name)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	char			**map;
	t_figure_list	*figure;

	if (argc != 2)
	{
		print_usage_msg(argv[0]);
		return (1);
	}
	if (ft_reader(argv[1]) > 0)
		figure = ft_create_list(argv[1]);
	else
	{
		write(1, "error\n", 6);
		return (1);
	}
	map = ft_create_map(figure);
	while (!ft_try(figure, map, 0, 0))
		map = ft_expand_map(map);
	ft_print_map(map);
	return (0);
}
