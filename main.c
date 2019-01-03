/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/03 15:54:11 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buff[21];

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if ((check(buff, fd)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("Everything is good mah boi.\n");
	return (0);
}
