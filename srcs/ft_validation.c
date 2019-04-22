/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:12:56 by daharwoo          #+#    #+#             */
/*   Updated: 2018/12/18 20:52:11 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_connection(const char *block)
{
	int i;
	int touch;

	touch = 0;
	i = 0;
	while (i < BUFF_SIZE)
	{
		if (block[i] == '#')
		{
			if ((i + 1) < BUFF_SIZE && block[i + 1] == '#')
				touch++;
			if ((i - 1) >= 0 && block[i - 1] == '#')
				touch++;
			if ((i + 5) < BUFF_SIZE && block[i + 5] == '#')
				touch++;
			if ((i - 5) >= 0 && block[i - 5] == '#')
				touch++;
		}
		i++;
	}
	return (touch == 6 || touch == 8);
}

static int	ft_check_buffer(char *buf)
{
	int i;
	int shapes;
	int dots;

	i = BUFF_SIZE - 1;
	while (i > 0)
	{
		if (buf[i] != '\n')
			return (-1);
		i -= 5;
	}
	i = 0;
	shapes = 0;
	dots = 0;
	while (buf[i])
	{
		buf[i] == '#' ? shapes++ : shapes;
		buf[i] == '.' ? dots++ : dots;
		i++;
	}
	if (dots == 16 && shapes == 0)
		return (2);
	return ((dots == 12 && shapes == 4) ? ft_check_connection(buf) : 0);
}

int			ft_reader(char *argv)
{
	int		arr[2];
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	int		fd;

	ft_bzero(arr, sizeof(arr));
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buffer, BUFF_SIZE + 1)) > 0)
	{
		buffer[ret] = '\0';
		if (ft_check_buffer(buffer) != 1)
		{
			close(fd);
			return (0);
		}
		if (ft_check_buffer(buffer) == 2)
			arr[1]++;
		arr[0]++;
	}
	if (ft_strlen(buffer) == 21)
		return (0);
	return (arr[0] == arr[1] ? 0 : 1);
}
