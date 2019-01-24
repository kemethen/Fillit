/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:26:02 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/24 19:05:18 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!check_file(fd))
	{
		ft_putstr("error\n");
		return (0);
	}

	ft_putstr("Everything is good mah boi.\n");
	return (0);
}
