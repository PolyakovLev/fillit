/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:12:29 by daharwoo          #+#    #+#             */
/*   Updated: 2018/12/18 20:49:15 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_figure_list	*ft_create_figure(t_figure_list *figure, char *line)
{
	int		arr[3];
	char	**linesplit;

	ft_bzero(arr, sizeof(arr));
	linesplit = ft_strsplit(line, '\n');
	figure = (t_figure_list *)malloc(sizeof(t_figure_list));
	while (linesplit[arr[0]])
	{
		arr[1] = 0;
		while (linesplit[arr[0]][arr[1]])
		{
			if (linesplit[arr[0]][arr[1]] == '#')
			{
				figure->rows[arr[2]] = arr[0];
				figure->cols[arr[2]] = arr[1];
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
	ft_move_figure(figure);
	ft_strstrdel(linesplit);
	figure->next = NULL;
	return (figure);
}

t_figure_list			*ft_create_list(char *argv)
{
	int				arr[3];
	char			buffer[BUFF_SIZE + 1];
	t_figure_list	*head;
	t_figure_list	*current;
	t_figure_list	*prev;

	ft_bzero(arr, sizeof(arr));
	arr[2] = open(argv, O_RDONLY);
	while ((arr[1] = read(arr[2], buffer, BUFF_SIZE + 1)) > 0)
	{
		current = ft_create_figure(current, buffer);
		if (arr[0] == 0)
		{
			head = current;
			prev = current;
		}
		prev->next = current;
		prev = current;
		arr[0]++;
	}
	if (arr[0] == 1)
		current->next = NULL;
	close(arr[2]);
	return (head);
}
