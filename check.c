/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/01/24 19:30:17 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	check_format(char *buff)
{
	short	i;

	i = 0;
	while (i++ < 20)
	{
		if (!(i % 5) && buff[i - 1] != '\n')
			return (0);
		if (i % 5 && buff[i - 1] != '#' && buff[i - 1] != '.')
			return (0);
	}
	return (1);
}

static short	check_tetri(char *buff)
{
	short	i;
	short	sharp;
	short	link;

	i = 0;
	sharp = 0;
	link = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			++sharp;
			if (buff[i + 1] == '#')
				++link;
			if (i < 14 && buff[i + 5] == '#')
				++link;
		}
		++i;
	}
	if (sharp != 4 || link < 3)
		return (0);
	return (1);
}

short			check_file(int fd)
{
	short	ret;
	char	buff[546];
	t_tetri	*tetri;

	tetri = NULL;
	ret = read(fd, buff, 546);
	buff[ret] = '\0';
	if (!check_format(buff) || !check_tetri(buff))
		return (0);
	tetri = lstfill(buff, &tetri);
	fillit(tetri);
	return (ret);
}
