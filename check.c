/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/08 15:34:14 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetri(char *buf)
{
	int		i;
	int		sharp;
	int		link;

	i = 0;
	sharp = 0;
	link = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			++sharp;
			if (buf[i + 1] == '#')
				++link;
			if (i < 14 && buf[i + 5] == '#')
				++link;
		}
		++i;
	}
	if (sharp != 4 || link < 3)
		return (-1);
	return (0);
}

int		check_format(char *buf, int ret)
{
	int	i;

	while (ret > 0)
	{
		i = 0;
		while (++i <= 20)
		{
			if (i % 5 == 0 && buf[i - 1] != '\n')
				return (-1);
			if (i % 5 && buf[i - 1] != '#' && buf[i - 1] != '.')
				return (-1);
		}
		i--;
		if (ret > 20 && buf[i] != '\n')
			return (-1);
		if (check_tetri(buf) == -1)
			return (-1);
		ret -= 21;
		buf += 21;
	}
	return (0);
}

short	check_file(int fd)
{
	short	ret;
	char	*buff;
	t_tetri	*tetri;
	t_tetri	*tmp;

	buff = ft_strnew(546);
	tetri = NULL;
	ret = read(fd, buff, 546);
	buff[ret] = '\0';
	if (ret % 21 != 20)
		return (-1);
	if (check_format(buff, ret) == -1)
		return (-1);
	tetri = lstfill(buff, &tetri);
	fillit(tetri);
	free(buff);
	while (tetri)
	{
		tmp = tetri->next;
		free(tetri);
		tetri = tmp;
	}
	return (0);
}
