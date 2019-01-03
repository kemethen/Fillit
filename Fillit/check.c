/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:45:05 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/03 11:57:07 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../GNL/libft/libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		i;
	int		count;
	int		count_pnt;
	int		count_lnk;
	char	buff[21];

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (((ret = read(fd, buff, 21)) > 0))
	{
		buff[20] = '\0';
		ft_putstr("buff = ");
		ft_putchar('\n');
		ft_putstr(buff);
		ft_putchar('\n');
		i = 0;
		count = 0;
		count_pnt = 0;
		count_lnk = 0;
		while (buff[i] == '#' || buff[i] == '.' || buff[i] == '\n')
		{
			if (buff[i] == '#')
				count++;
			if (buff[i] == '.')
				count_pnt++;
			if ((buff[i] == '#' && buff[i + 1] == '#') || (buff[i] == '#' && buff[i + 5] == '#'))
				count_lnk++;
			i++;
		}
		if (buff[i] != '\0' || count != 4 || count_pnt != 12 || count_lnk < 3)
		{
			ft_putstr("Je bloque\n");
			ft_putchar(buff[i]);
			ft_putchar('\n');
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putchar('\n');
			ft_putstr("count = ");
			ft_putnbr(count);
			ft_putchar('\n');
			ft_putstr("count_pnt = ");
			ft_putnbr(count_pnt);
			ft_putchar('\n');
			ft_putstr("Error. Wrong format of tetriminos\n");
			return (0);
		}
	}
	ft_putstr("Tetriminoses are valids\n");
	return (0);
}
