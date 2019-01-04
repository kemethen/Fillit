/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/04 14:45:18 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	buff[21];

	if (ac < 2 || ac >= 3)
		return (0);
	fd = open(av[1], O_RDONLY);
	if ((check(buff, fd)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
