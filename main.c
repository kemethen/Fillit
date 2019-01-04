/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/04 19:58:00 by maolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buff[21];

	if (ac != 2)
	{
		ft_putstr("wrong usage\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!check_file(fd, buff))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("Everything is good mah boi.\n");
	return (0);
}
