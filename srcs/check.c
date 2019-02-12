/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:25:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/12 18:23:29 by kemethen         ###   ########.fr       */
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

int		msize(t_tetri **t)
{
	int		cnt;
	int		racine;

	racine = 1;
	cnt = 1;
	while ((*t)->next)
	{
		if ((*t)->next)
			*t = (*t)->next;
		++cnt;
	}
	while ((*t)->prev)
	{
		if ((*t)->prev)
			*t = (*t)->prev;
	}
	cnt *= 4;
	while (racine * racine < cnt)
		++racine;
	return (racine);
}

int		check_file(int fd, t_var *v)
{
	int		ret;
	char	*buff;
	char	**map;
	char	**lastmap;
	t_tetri	*tetri;

	buff = ft_strnew(546);
	tetri = NULL;
	ret = read(fd, buff, 546);
	buff[ret] = '\0';
	if (ret % 21 != 20)
		return (-1);
	if (check_format(buff, ret) == -1)
		return (-1);
	tetri = lstfill(buff, &tetri);
	map = (char **)malloc(sizeof(char *) * (msize(&tetri) + 1));
	map[msize(&tetri)] = NULL;
	while ((*v).j < msize(&tetri))
		map[(*v).j++] = ft_strndup(".............", msize(&tetri));
	lastmap = fillit(tetri, v, map);
	fillitfree(buff, tetri, lastmap);
	return (0);
}
