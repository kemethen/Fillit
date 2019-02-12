/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:26:02 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/12 18:22:30 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_var	*v;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(v = (t_var *)malloc(sizeof(t_var))))
		return (-1);
	ft_bzero(v, sizeof(t_var));
	fd = open(av[1], O_RDONLY);
	if (check_file(fd, v) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (0);
}
