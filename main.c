/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:26:02 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/22 14:51:50 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buff[21];

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!check_file(fd, buff))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("Everything is good mah boi.\n");
	close(fd);
	return (0);
}
